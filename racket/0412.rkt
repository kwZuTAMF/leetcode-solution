#lang racket

; https://leetcode.com/problems/fizz-buzz/
(define/contract (fizz-buzz n)
  (-> exact-integer? (listof string?))
  (for/list ([i (in-inclusive-range 1 n)])
    (if (= (remainder i 3) 0)
        (if (= (remainder i 5) 0) "FizzBuzz" "Fizz")
        (if (= (remainder i 5) 0) "Buzz" (number->string i)))
    )
  )

(module+ test
  (require rackunit)
  (check-equal? (fizz-buzz 3) '("1" "2" "Fizz"))
  (check-equal? (fizz-buzz 5) '("1" "2" "Fizz" "4" "Buzz"))
  (check-equal? (fizz-buzz 15) '("1" "2" "Fizz" "4" "Buzz" "Fizz" "7" "8" "Fizz" "Buzz" "11" "Fizz" "13" "14" "FizzBuzz")))
