#!/bin/bash
declare -i tmp
declare -i count_0=0
declare -i count_1=0

if [ ! -f code ]; then
	gcc mycode.c -o code
fi

if [ ! -f test ]; then
	gcc someonecode.c -o test
fi

for i in {1..100};
do
    tmp=$(./code | grep "定" | cut -c 10-11)
    count_0=count_0+tmp
    tmp=$(./test | grep "定" | cut -c 10-16)
    count_1=count_1+tmp
done

echo "我寫的code(有Prune and Search)執行100次平均定位次數為$(($count_0/100))"
echo "別人的code(無Prune and Search)執行100次平均定位次數為$(($count_1/100))"
