python3 ../materials/linters/cpplint.py --extensions=c *.c *.h io/* file/* data/*
cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h io/* file/* data/*