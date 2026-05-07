# Algorithm Code Library

数据结构与算法代码库，按算法主题组织，便于复习和复用。

## 目录结构

```
.
├── algorithms/          # 精选复习（按算法命名，每个主题 1-2 个例题）
│   ├── kmp.cpp                         KMP 字符串匹配
│   ├── binary_tree_manual.cpp          手写二叉树
│   ├── binary_tree_level_order.cpp     树的层序遍历 (BFS)
│   ├── binary_tree_diameter.cpp        二叉树直径 (DFS 后序)
│   ├── linked_list_manual.cpp          手写链表
│   ├── linked_list_cycle.cpp           Floyd 判圈
│   ├── merge_k_sorted_lists.cpp        合并 K 个有序链表 (堆/分治)
│   ├── circular_queue.cpp             手写循环队列
│   ├── min_stack.cpp                  最小栈 (O(1) getMin)
│   ├── infix_to_postfix.cpp           中缀转后缀表达式
│   ├── reverse_polish_notation.cpp    逆波兰表达式求值
│   ├── decode_string.cpp             字符串解码 (栈+递归)
│   ├── largest_rectangle_histogram.cpp 柱状图最大矩形 (单调栈)
│   ├── daily_temperatures.cpp         每日温度 (单调栈)
│   ├── trapping_rain_water.cpp        接雨水 (多解法)
│   ├── sliding_window_maximum.cpp     滑动窗口最大值 (单调队列)
│   ├── minimum_window_substring.cpp   最小覆盖子串 (滑动窗口)
│   ├── container_with_most_water.cpp  盛水最多容器 (双指针)
│   ├── find_duplicate_number.cpp      寻找重复数 (Floyd+二分)
│   ├── two_sum_all_pairs.cpp          两数之和所有对 (双指针去重)
│   ├── dutch_flag.cpp                 颜色分类 (三路划分)
│   ├── dfs_full_permutation.cpp       全排列 (回溯)
│   ├── dfs_subset.cpp                 子集枚举 (回溯)
│   ├── dfs_n_queens.cpp               N皇后 (回溯+剪枝)
│   ├── dfs_island_count.cpp           岛屿数量 (Flood Fill)
│   ├── dfs_maze.cpp                   迷宫路径 (网格DFS)
│   ├── bfs_horse.cpp                  马遍历棋盘 (网格BFS)
│   └── recursive_decode.cpp           外星密码 (嵌套递归)
│
└── inbox/               # 待处理归档（按原名存放，未经整理）
```

## 分类总览

| 类别 | 文件 |
|------|------|
| 字符串匹配 | `kmp` |
| 二叉树 | `binary_tree_manual` `binary_tree_level_order` `binary_tree_diameter` |
| 链表 | `linked_list_manual` `linked_list_cycle` |
| 堆/分治 | `merge_k_sorted_lists` |
| 队列 | `circular_queue` |
| 栈应用 | `min_stack` `infix_to_postfix` `reverse_polish_notation` `decode_string` |
| 单调栈 | `largest_rectangle_histogram` `daily_temperatures` |
| 滑动窗口 | `sliding_window_maximum` `minimum_window_substring` |
| 双指针 | `container_with_most_water` `find_duplicate_number` `two_sum_all_pairs` |
| 排序 | `dutch_flag` |
| DFS 回溯 | `dfs_full_permutation` `dfs_subset` `dfs_n_queens` |
| 网格搜索 | `dfs_island_count` `dfs_maze` `bfs_horse` |
| 递归 | `recursive_decode` |
| 多解法 | `trapping_rain_water` |
