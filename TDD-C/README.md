String manipulation
===================

Requirements
------------

- GCC
- CUnit
- bash

Build
-----

Start by building the library:

    $ ./build.sh library

This will create the static library `tddc.a` which you can link to
your projects / tests.
Then you can build the unit tests with:

    $ ./build.sh test

And run the tests:

    $ ./test_cpch
    $ ./test_catch
    $ ./test_cpnch
    $ ./test_catnch

Documentation
-------------

CUnit:
- CUnit: http://cunit.sourceforge.net/doc/
- CUnit slides: http://fr.slideshare.net/seb478/ecam-os2015c-unitslides

C:
- The C Programming Language: K&R

