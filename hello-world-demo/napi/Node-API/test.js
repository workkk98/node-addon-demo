let addon = require('bindings')('hello');

console.time('addon fabonacci')
addon.fabonacci()
console.timeEnd('addon fabonacci')


function fabonacci(a) {
  if (a === 1 || a === 2) {
    return a
  }
  return fabonacci(a - 1) + fabonacci(a - 2)
}

console.time('fabonacci')
fabonacci(20)
console.timeEnd('fabonacci')