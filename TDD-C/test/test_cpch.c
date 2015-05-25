#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "tddc/tddc.h"

void test_1()
{
  char destination[20];
  const char* source = "hello";
  int result;

  /*
   * This should work as expected, there is enough room in
   * `destination` to hold the string + terminating \0
   */
  result = cpch(destination, 20, source);
  CU_ASSERT_STRING_EQUAL(destination, source);
  CU_ASSERT_EQUAL(result, 5);

  /*
   * This should work as expected, there is enough room in
   * `destination` to hold the string + terminating \0
   */
  result = cpch(destination, 20, "hel\0lo");
  CU_ASSERT_STRING_EQUAL(destination, "hel");
  CU_ASSERT_EQUAL(result, 3);

  /*
   * Here we specify not to use more than 6 characters inside
   * `destination`, so we should end up with 'h', 'e', 'l', 'l', 'o', \0
   */
  result = cpch(destination, 6, source);
  CU_ASSERT_STRING_EQUAL(destination, "hello");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Here we specify not to use more than 5 characters inside
   * `destination`, so we should end up with 'h', 'e', 'l', 'l', \0
   */
  result = cpch(destination, 5, source);
  CU_ASSERT_STRING_EQUAL(destination, "hell");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Here we specify not to use more than 3 characters inside
   * `destination`, so we should end up with 'h', 'e', \0
   */
  result = cpch(destination, 3, source);
  CU_ASSERT_STRING_EQUAL(destination, "he");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Nothing should be done here
   */
  memset(destination, '?', 20);
  cpch(destination, 0, source);
  result = memcmp(destination, "????????????????????", 20);
  CU_ASSERT_EQUAL(result, 0);
}

int main(int argc, const char** argv)
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("cpch", NULL, NULL);

  CU_add_test(suite, "Test 1", test_1);

  CU_basic_run_tests();

  return 0;
}
