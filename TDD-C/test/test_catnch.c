#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "tddc/tddc.h"

void test_1()
{
  char destination[20] = "hello";
  const char* source = "world";
  int result;

  /*
   * This should work as expected, there is enough room in
   * `destination` to hold everything.
   */
  result = catnch(destination, 20, source, 5);
  CU_ASSERT_STRING_EQUAL(destination, "helloworld");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Concatenate only the 3 first characters of source
   */
  result = catnch(destination, 20, source, 3);
  CU_ASSERT_STRING_EQUAL(destination, "helloworldwor");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * And again as before, 3 first characters
   */
  result = catnch(destination, 20, source, 3);
  CU_ASSERT_STRING_EQUAL(destination, "helloworldworwor");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Copying 5 characters would overflow destination, only 3
   * should be copied here.
   */
  result = catnch(destination, 20, source, 5);
  CU_ASSERT_STRING_EQUAL(destination, "helloworldworworwor");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * Make sure everything works for empty strings
   */
  strncpy(destination, "", 20);
  result = catnch(destination, 20, source, 5);
  CU_ASSERT_STRING_EQUAL(destination, "world");
  CU_ASSERT_EQUAL(result, 5);

  /*
   * And empty strings with limited chars
   */
  strncpy(destination, "", 20);
  result = catnch(destination, 20, source, 3);
  CU_ASSERT_STRING_EQUAL(destination, "wor");
  CU_ASSERT_EQUAL(result, 5);
}

int main(int argc, const char** argv)
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("catnch", NULL, NULL);

  CU_add_test(suite, "Test 1", test_1);

  CU_basic_run_tests();

  return 0;
}

