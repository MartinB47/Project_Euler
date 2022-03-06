countdigits = function(n) {
  result = floor(log10(abs(n)))
  result[!is.finite(result)] = 0
  result
}

{
sum = 0;
number = 5**34;
  for (i in 1:303) {
    digit = number %% 10;
    sum = sum + digit;
    number = (number - digit) / 10;
  }
}


