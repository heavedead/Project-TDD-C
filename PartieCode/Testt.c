#include <stdio.h>
#include <limits.h>
#include <CUnit/CUnit.h>

/*
 * Fonction toMin.
 *
 * La fonction "enMInute" prends en paramètre une valeur numérique
 * qui est interprété comme un nombre de seconde.
 * La fonction détermine ensuite le nombre de minute réalisable
 * avec la valeur d'entrée.
 * Si le nombre de seconde est inférieur à 60, celle ci retournera
 * une valeur nulle. (égal à zero)
 *
 * @exception : une valeur négative entrainera un retour
 * de valeur "-1"
 *
 * @author Sicard Samuel [Ameziel]
 */
int toMin(int secVal) 
{
    if (secVal < 0) {
        return -1;
    }
    return secVal / 60;
}

void test_toMin(void) 
{

    CU_ASSERT_EQUAL(toMin(0),0);
    CU_ASSERT_EQUAL(toMin(70),1);
    CU_ASSERT_EQUAL(toMin(240),4);
    CU_ASSERT_EQUAL(toMin(INT_MAX),35791394);
    CU_ASSERT_EQUAL(toMin(-40), -1);

}

int main(int argc, const char** argv)
{

    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Test Suite limits", NULL, NULL);

    CU_add_test(suite, "fonction de test", test_toMin);

    /* 
     * Pour générer un fichier xml
     * CU_set_output_filename("Results");
     * CU_automated_run_tests();
     */
    
    CU_basic_run_tests();
    /* CU_cleanup_registry(); */
    return 0;

}
