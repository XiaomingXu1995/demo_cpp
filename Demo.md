# Demo.md is used to show the log of the demo program.

## Bloom Filter

### Generating bloom filter and unordered_set dictionary before the retrieving.

Parameters for evaluation:
* DictSize: number of elements in the dictionary(bloom filter and unordered_set).
* BFSize: the number of bits(implemented with char) for Bloom Filter array.
* PBitOne: proportion of bit `1` in the bloom filter. More `1` means less efficiency of BF.
* QuerySize: number of elements to retrieve bloom filter and unordered_set.
* Func1BF: Proportion of determining the elements not in the dictionary with the first hash function in Bloom Filter.
* Func2BF: Proportion of determining the elements not in the dictionary with the second hash function in Bloom Filter.
* Func3BF: Proportion of determining the elements not in the dictionary with the third hash function in Bloom Filter.
* NoneBF: Proportion of determining whether the elements are in the dictionary or not with unordered_set(Bloom filter invalid)
* tBF: time of Bloom filter retrieving
* tSet: time of unordered_set retrieving
* tGBF: time of BF generation
* tGSet: time of unordered_set generation
* speedUp: speedUp of retrieving only
* SumSpeedUp: speed up of sum time of generation and retrieving.


|DictSize|BFSize|PBitOne|QuerySize|Func1BF|Func2BF|Func3BF|NoneBF|
|---:|---:|---:|---:|---:|---:|---:|---:|
|2^26|2^29|0.313|2^30|0.687|0.152|0.034|0.127|
|2^26|2^29|0.313|2^28|0.687|0.152|0.034|0.127|
|2^26|2^29|0.313|2^26|0.687|0.152|0.034|0.127|
|2^24|2^29|0.089|2^30|0.911|0.055|0.003|0.031|
|2^24|2^29|0.089|2^28|0.910|0.055|0.003|0.031|
|2^24|2^29|0.089|2^26|0.911|0.055|0.003|0.031|
|2^22|2^29|0.023|2^30|0.977|0.015|0.000|0.008|
|2^22|2^29|0.023|2^28|0.977|0.015|0.000|0.008|
|2^22|2^29|0.023|2^26|0.977|0.015|0.000|0.008|
|2^20|2^29|0.006|2^30|0.994|0.004|0.000|0.002|
|2^20|2^29|0.006|2^28|0.994|0.004|0.000|0.002|
|2^20|2^29|0.006|2^26|0.994|0.004|0.000|0.002|


|DictSize|BFSize|QuerySize|timeBF|timeSet|timeGeneBF|timeGeneSet|speedUp|SumSpeedUp|
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
|2^26|2^29|2^30|76.56|88.24|41.97|37.52|1.15|1.06|
|2^26|2^29|2^28|14.11|18.54|42.00|37.58|1.31|1.00|
|2^26|2^29|2^26|2.84|4.06|37.39|35.40|1.43|0.98|
|2^24|2^29|2^30|21.02|57.70|8.47|7.98|2.75|2.23|
|2^24|2^29|2^28|5.25|14.44|8.43|7.98|2.75|1.64|
|2^24|2^29|2^26|1.32|3.61|8.45|7.98|2.74|1.19|
|2^22|2^29|2^30|11.87|56.00|1.90|1.62|4.72|4.19|
|2^22|2^29|2^28|2.98|14.08|1.88|1.63|4.73|3.23|
|2^22|2^29|2^26|0.74|3.52|1.92|1.64|4.75|1.94|
|2^20|2^29|2^30|8.68|48.85|0.39|0.24|5.62|5.41|
|2^20|2^29|2^28|2.16|12.20|0.40|0.24|5.64|4.86|
|2^20|2^29|2^26|0.54|3.05|0.39|0.24|5.64|3.53|


