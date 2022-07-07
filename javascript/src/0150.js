/**
 * @param {string[]} tokens
 * @return {number}
 */
function evalRPN(tokens) {
  return tokens.reduce((stk, token) => {
    switch (token) {
      case '+':
      case '-':
      case '*':
      case '/':
        {
          let y = stk.pop()
          let x = stk.pop()
          switch (token) {
            case '+': stk.push(x + y); break
            case '-': stk.push(x - y); break
            case '*': stk.push(x * y); break
            case '/': stk.push((x / y) | 0); break
          }
        }
        break
      default:
        stk.push(+token)
        break
    }
    return stk
  }, []).pop()
}

{
  const { strictEqual } = require('assert')

  const CASES = [
    [['2', '1', '+', '3', '*'], 9],
    [['4', '13', '5', '/', '+'], 6],
    [['10', '6', '9', '3', '+', '-11', '*', '/', '*', '17', '+', '5', '+'], 22],
  ]

  for (const [tokens, excepted] of CASES) {
    const actual = evalRPN(tokens)
    strictEqual(actual, excepted)
  }

  console.time()
  for (const [tokens, _] of CASES) {
    for (let i = 0; i < 100000; i++) {
      evalRPN(tokens)
    }
  }
  console.timeEnd()
}
