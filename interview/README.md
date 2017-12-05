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

### 组合数
```js
function C(n, m) {
    let de = 1, nu = 1, diff=n-m;
    for (let i=1; i<=n; i++) {
        (i>m) && (nu*=i);
        (i<=diff) && (de*=i);
    }
    return nu/de;
}
console.log(C(10,2))
```

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
### π/4 = sum<0,n>{(-1)^n*1/(2n+1)}
```js
//pi = 3.1415926535898
let times = 200000000;
let sum = 0;
for (let n=0,k=1; n<=times; n++,k=-k) {
    sum += k/(2*n+1);
}
console.log(4*sum);
//3.141592603589817
```

### π = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - (4/(12*13*14) ...
### π = 3 + 4*sum<1,n>{(-1)^n*1/((2*n)*(2*n+1)*(2*n+2))}
```js
let times = 405;
let sum = 0;
for (let n=1,k=1; n<=times; n++,k=-k) {
    sum += k/((2*n)*(2*n+1)*(2*n+2));
}
console.log(3+4*sum);
//3.1415926695894734
```

### π/4=2/3*4/3*4/5*6/5*6/7*8/7*8/9 ...
### π/4= multi<1,n>{(2*n)/(2*n+1) * (2*n+2)/(2*n+1)}

```js
let times = 500000000;
let sum = 1;
for (let n=1; n<=times; n++) {
    sum *= (2*n)/(2*n+1)*(2*n+2)/(2*n+1);
}
console.log(4*sum);
//3.1415926591456005
```

### π/2=1+1/3+1/3*2/5+1/3*2/5*3/7+1/3*2/5*3/7*4/9+...

```js
let times = 27;
let sum = 0;
for (let n=1; n<=times; n++) {
    let multi = 1;
    const count = 2*n+1;
    for (let m=3,y=1; m<=count; m+=2,y++) {
        multi *= y/m;
    }
    sum += multi;
}
console.log(2*(sum+1));
//3.141592653589295
```

### π/4=sum<0,n>{(-1)^n*4/((2n+1) * 5^(2n+1))-(-1)^n*1/((2n+1) * 239^(2n+1))}

```js
let times = 5;
let sum = 0;
for (let n=0,k=1; n<=times; n++,k=-k) {
    const m = 2*n+1;
    sum += k*4/(m*Math.pow(5, m))-k/(m*Math.pow(239, m));
}
console.log(4*sum);
//3.141592652615309
```

### π=sum<0,n>{(-1)^n/(2*n+1) * (48/(18^(2*n+1))+32/(57^(2*n+1))-20/(239^(2*n+1)))}

```js
let times = 3;
let sum = 0;
for (let n=0,k=1; n<=times; n++,k=-k) {
    const m = 2*n+1;
    sum += k/m*(48/Math.pow(18, m)+32/Math.pow(57, m)-20/Math.pow(239, m));
}
console.log(sum);
//3.141592653562973
```

### π=1/64*sum<0,n>{(-1)^n/(2^(10*n)) * (-32/(4*n+1)-1/(4*n+3)+256/(10*n+1)-64/(10*n+3)-4/(10*n+5)-4/(10*n+7)+1/(10*n+9))}

```js
let times = 2;
let sum = 0;
for (let n=0,k=1; n<=times; n++,k=-k) {
    sum += k/Math.pow(2, 10*n)*(-32/(4*n+1)-1/(4*n+3)+256/(10*n+1)-64/(10*n+3)-4/(10*n+5)-4/(10*n+7)+1/(10*n+9));
}
console.log(sum/64);
//3.14159265364205
```

### 在一个2×2的方格内进行随机投点，记下点落在半径为1的圆内的次数𝑛0以及总的投点次数n，π=4𝑛0/n。

```js
let times = 100000000;
let sum = 0;
for (let n=0; n<=times; n++) {
    const x = Math.random();
    const y = Math.random();
    if (x*x+y*y<1) {
        sum++;
    }
}
console.log(4*sum/times);
```
