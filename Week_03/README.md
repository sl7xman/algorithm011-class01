# 学习笔记
## 递归编程框架：
```
void recursion( int level, int param ) {
        //terminator
        if( level > MAX_LEVLEL ) {
            process_result();
            return;    
        }
        //process current logic
        process(level, param);

        //drill down
        recursion( level+1, param);

        //restore current status
}
```

