#!/usr/bin/ruby

$facs = [1]

def fill_facs(n)

  for i in 1..n; $facs << $facs[-1] * i; end

end

def n_perm(n)

  fill_facs 9
  p $facs 

  perm = Array.new

  digits = 10

  for i in 1..9
    perm[i] = n / $facs[digits - 1 - i]
    digits = digits % $facs[digits - 1 - k]
  end

end


n_perm(10)
