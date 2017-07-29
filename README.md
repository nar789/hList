**HList**
=================
### **HList** is like a linked list for (c)[HUME](http://hume.co.kr).
### Created by Junghun,Lee <tony92511@hanmail.net>

-----------
## Documents

>## 1. Insert data
>>source
>><pre><code>hList list;
>>D data(1,1);
>>list+data+data+data+D(3,3);
>>cout&lt;&lt;list&lt;&lt;endl;
>></code></pre>
>>output
>><pre><code>[1,1] [1,1] [1,1] [3,3]</code></pre>

>## 2. Remove Data

>#### 1) FIFO
>>source
>><pre><code>cout&lt;&lt;list&lt;&lt;endl;
>>list--;
>>cout&lt;&lt;list&lt;&lt;endl;</code></pre>
>>output
>><pre><code>[1,1] [2,2] [3,3] [4,4]
>>[1,1] [2,2] [3,3] </code></pre>

>#### 2) LIFO
>>source
>><pre><code>cout&lt;&lt;list&lt;&lt;endl;
>>--list;
>>cout&lt;&lt;list&lt;&lt;endl;
>></code></pre>
>>output
>><pre><code>[1,1] [2,2] [3,3] [4,4]
>>[2,2] [3,3] [4,4]
>></code></pre>

>## 3. For each
>>source
>><pre><code>hList list;
>>list+D(1,1)+D(2,2)+D(3,3)+D(4,4);
>>for(E itr : list){
>>	cout&lt;&lt;itr;
>>}</code></pre>
>>output
>><pre><code>[1,1] [2,2] [3,3] [4,4]</code></pre>

>## 4. At, Size, Clear
>>source
>><pre><code>hList list;
>>list+D(1,1)+D(2,2)+D(3,3)+D(4,4);
>>cout&lt;&lt;list.Size();
>>cout&lt;&lt;list[3];
>>list.Clear();
>>cout&lt;&lt;list.Size();</code></pre>
>>output
>><pre><code>4
>>[4,4]
>>0</code></pre>

