### 使用for循环遍历显示每个字母
```js
var str='abc';
for (var i=0, len=str.length; i < len; i++) {
    console.log();
}
```
- `注意点：`不能写成 `i<str.length`

### 一种有x盏灯全部亮着，能够被3整除的切换一下开关，然后再能够被5整除的切换一下开关，结果有多少盏灯亮着
```js
_.countBy(_.map(new Array(30), (m,i)=>!((i+1)%3)).map((m,i)=>(!((i+1)%5))^m),(i)=>!i).true
```

### 编写表情传输过程中的字符转义的算法

### 编写类似微信聊天的时间分段

### 编写润年的算法

```js
var leap = (!(y%4)&(!!(y%100)))|(!(y%400));
```

### 编写冒泡排序的算法

### 编写随机均匀分布的算法
* data = [1, 2, 3, 4]; 均匀分布到50个点上, genAllData(data, 50)
```js
var _ = require('lodash');

function genAllData(data, length) {
    const len = data.length;
    const step = parseInt(length/len);
    const tail = length%len;
    var flags = {}, d;
    for (var i=len; i < length; i++) {
        do {
            if (length-i <= tail) {
                d = tail+i-length;
                break;
            }
            d = _.random(0, len-1);
            flags[d] = flags[d] ? flags[d]+1 : 1;
        } while (flags[d] >= step);

        data[i] = data[d];
    }
    return data;
}

var c = {};
var a = [1,2,3,4];
var b = genAllData(a, 50);
_.forEach(b, (k)=>c[k]=(c[k]||0)+1)
console.log(c);
```

### 判断json的错误值

### 返回json的格式

### 优先级
```js
var url = 'http://localhost:3000';
var status = 'done'
var ret = url || (status === 'done' ? 'http://localhost:3000/done' : 'http://localhost:3000/undo');
//ret: http://localhost:3000
var ret = url || status === 'done' ? 'http://localhost:3000/done' : 'http://localhost:3000/undo';
//ret: http://localhost:3000/done
```

### 物流公司的价格采用阶梯价格，采用数据库的方式表现出来。如果现在拉来的货为n吨，价格应该为多少。
```js
    //物流公司在设置时候min必须从0开始，如 [ {value: 10, min: 0}, {value: 8, min: 10}, {value: 7, min: 20 } ] 表示0-10为10元/吨，10-20为8元/吨，20以上为7元/吨
    price: [ { value: { type: Number }, min: { type: Number } } ], // 每吨的价格，单位为元/吨（采用阶梯价格）
    _.findLast(price, o => o.min <= weight);
```

### 设计验证码的数据结构，超时时间为2小时，如果在超时时间内连续发送了3条，则提示操作过于频繁。

### 素数
```js
const _ = require('lodash');
const n = 100;
const list = [];
for (let i=2; i<=n; i++) {
    _.every(list, o=>i%o) && list.push(i);
}
list.unshift(1);
console.log(list);
```

### 计算二进制
```js
const result = [];
for (let j = n; j > 0; j = Math.floor(j/2)) {
    result.unshift(j%2);
}
console.log(result);
```


### 有1000桶酒，其中1桶有毒。而一旦吃了，毒性会在1周后发作。现在我们用小老鼠做实验，要在1周内找出那桶毒酒，问最少需要多少老鼠。
```js
const _ = require('lodash');
const getBits = (n) => {
    const bits = [];
    for (let j = n; j > 0; j = Math.floor(j/2)) {
        bits.unshift(j%2);
    }
    return bits;
}
const n = 1000;
const list = _.fill(Array(n), 0);
const result = [];
const trueIndex = _.random(0, n-1);
list[trueIndex] = 1;
_.forEach(list, (o, i)=>{
    const bits = getBits(i+1);
    const indexes = [];
    _.forEach(bits, (m, k)=>{
        if (m) {
            k = bits.length-1-k;
            result[k] = result[k]|o;
            indexes.unshift(k);
        }
    });
    console.log('第'+i+'桶牛奶喂了第'+indexes.join(',')+'只老鼠');
});

let sum = 0;
_.forEach(result, (o, i)=>sum+=o*Math.pow(2, i));

console.log(sum === trueIndex+1 ? '验证成功' : '验证失败', '总共需要'+result.length+'只老鼠');
```

### π = (4/1) - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + (4/13) - (4/15) ...

```js
//pi = 3.1415926535898
let n = 40000000;
let sum = 0;
for (let i=1; i<n; i+=2) {
    sum += 4/i*(((i+1)/2) & 1 ? 1 : -1);
}
console.log(sum);
//3.141592603589817
```

### π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - (4/(12*13*14) ...

```js
let n = 500;
let sum = 0;
for (let i=2; i<n; i+=2) {
    sum += 4/(i*(i+1)*(i+2))*((i/2) & 1 ? 1 : -1);
}
console.log(3+sum);
//3.1415926695894734
```

### π/4=2/3*4/3*4/5*6/5*6/7*8/7*8/9 ...

```js
let n = 40000000;
let sum = 1;
for (let i=3; i<n; i+=2) {
    sum *= (i-1)*(i+1)/(i*i);
}
console.log(4*sum);
//3.1415926931293625
```
