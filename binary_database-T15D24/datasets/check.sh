python3 ../materials/linters/cpplint.py --extensions=c *.c *.h io/* log/*
cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h io/* log/*