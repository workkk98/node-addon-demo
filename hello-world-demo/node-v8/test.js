const test = require('./build/Release/hello');

test(function () {
  console.log('arguments', arguments)
})

// console.log(test.add(1, 2));

// console.log(test.hello()); // 输出hello
