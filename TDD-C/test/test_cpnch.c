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
  result = cpnch(destination, 20, source, 5);
  CU_ASSERT_STRING_EQUAL(destination, source);
  CU_ASSERT_EQUAL(result, 5);

  /*
   * This should also work as expected because cpnch
   * should stop at the end of src if \0 is found
   */
  result = cpnch(destination, 20, source, 6);
  CU_ASSERT_STRING_EQUAL(destination, source);
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Only the first 3 characters of src should be
   * copied here.
   */
  result = cpnch(destination, 20, source, 3);
  CU_ASSERT_STRING_EQUAL(destination, "hel");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Only copy the 2 first characters + terminating \0
   * even though we ask for 5 characters because destination
   * is shorter
   */
  result = cpnch(destination, 3, source, 5);
  CU_ASSERT_STRING_EQUAL(destination, "he");
  CU_ASSERT_EQUAL(result, 5);
}

int main(int argc, const char** argv)
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("cpnch", NULL, NULL);

  CU_add_test(suite, "Test 1", test_1);

  CU_basic_run_tests();

  return 0;
}
