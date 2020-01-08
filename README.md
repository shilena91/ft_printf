# ft_printf

Project ft_printf at Hive Helsinki. I have to reproduce function printf in C language. More detailed and requirement are in pdf file. This is just mandatory part. I will do bonus part in the future. Keep updated!

<img width="210" alt="Screen Shot 2019-12-31 at 5 18 51 PM" src="https://user-images.githubusercontent.com/44005264/71625659-a2ffb080-2bf1-11ea-8cdf-11d49cb71e63.png">

## Function's limit:

1. It only works with `dicspouxXf` conversions, with flags `hh, ll, l, L`
2. It doesn't give exact result with precision bigger than 19 with float type as original printf.
3. It doesn't explicily define -0 and 0 with float type as original printf.
4. It doesn't cover undefined behaviors.
5. It doesn't work if you put flags in wrong order.
