#!/bin/bash

function usage() {
  echo "usage: build.sh library | test | clean"
  exit 1
}

function build_library() {
  echo "Create object file 'tddc.o'"
  gcc -std=c99 -Werror -Wall -Iinc -c src/tddc.c

  echo "Create static library 'tddc.a'"
  ar rcs tddc.a tddc.o
}

function remove_temporaries() {
  echo "Remove library"
  rm -rf tddc.a tddc.o

  echo "Remove tests"
  rm -rf test_cpch test_cpnch test_catch test_catnch
}

function build_tests() {
  echo "Creating 'test_cpch'"
  gcc -std=c89 -Werror -Wall -Iinc -o test_cpch test/test_cpch.c -lcunit tddc.a

  echo "Creating 'test_cpnch'"
  gcc -std=c89 -Werror -Wall -Iinc -o test_cpnch test/test_cpnch.c -lcunit tddc.a

  echo "Creating 'test_catch'"
  gcc -std=c89 -Werror -Wall -Iinc -o test_catch test/test_catch.c -lcunit tddc.a

  echo "Creating 'test_catnch'"
  gcc -std=c89 -Werror -Wall -Iinc -o test_catnch test/test_catnch.c -lcunit tddc.a
}

function run_tests() {
  echo "===== TEST_CPCH ====="
  ./test_cpch

  echo

  echo "===== TEST_CPNCH ====="
  ./test_cpnch

  echo

  echo "===== TEST_CATCH ====="
  ./test_catch

  echo

  echo "===== TEST_CATNCH ====="
  ./test_catnch
}

if [ "$#" -ne 1 ]
then
  usage
fi

case "$1" in
  "library")
    build_library
  ;;

  "clean")
    remove_temporaries
  ;;

  "test")
    build_tests
  ;;

  "run")
    run_tests
  ;;

  *)
    echo "Unknown parameter '$1'"
    usage
  ;;
esac

