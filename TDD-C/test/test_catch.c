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
  result = catch(destination, 20, source);
  CU_ASSERT_STRING_EQUAL(destination, "helloworld");
  CU_ASSERT_EQUAL(result, 5);

  result = catch(destination, 20, source);
  CU_ASSERT_STRING_EQUAL(destination, "helloworldworld");
  CU_ASSERT_EQUAL(result, 5);

  result = catch(destination, 20, source);
  CU_ASSERT_STRING_EQUAL(destination, "helloworldworldworl");
  CU_ASSERT_EQUAL(result, 5);
}

int main(int argc, const char** argv)
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("catch", NULL, NULL);

  CU_add_test(suite, "Test 1", test_1);

  CU_basic_run_tests();

  return 0;
}

