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
