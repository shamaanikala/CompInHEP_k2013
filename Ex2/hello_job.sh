#!/bin/bash

hello="Ex2-1"

for n in {1..10}
do
    ./$hello $n > ${n}bash.out&
done
wait