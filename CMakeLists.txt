cmake_minimum_required(VERSION 3.22)
project(DataStructure)
set(CMAKE_CXX_STANDARD 14)
add_executable(find_max_sub_sequence 2/find_max_sub_sequence.cpp)
add_executable(Hoare_partition 7/Hoare_partition.cpp)
add_executable(main main.cpp)
target_sources(main PUBLIC "3/vector.h")
target_sources(main PUBLIC "3/List.h" "3/List.cpp" "4/BinarySearchTree.h")
add_executable(balance_symbol_use_stack 3/balance_symbol_use_stack.cpp)
add_executable(3.1 3/3.1.cpp)
add_executable(3.4_3.5 3/3.4_3.5.cpp)
add_executable(3.6 3/3.6.cpp)
target_sources(main PUBLIC "3/vector.h" "5/HashTable.h" "5/HashTable_2.h" "6/BinaryHeap.h")

add_executable(2 leetcode/2.cpp)

add_executable(1 leetcode/1.cpp)
add_executable(3 leetcode/3.cpp)

add_executable(11 leetcode/11.cpp)
add_executable(4 leetcode/4.cpp)
add_executable(5 leetcode/5.cpp)
add_executable(704 leetcode/704.cpp)
add_executable(35 leetcode/35.cpp)
add_executable(34 leetcode/34.cpp)
add_executable(69 leetcode/69.cpp)
add_executable(367 leetcode/367.cpp)
add_executable(27 leetcode/27.cpp)
add_executable(283 leetcode/283.cpp)
add_executable(26 leetcode/26.cpp)
add_executable(844 leetcode/844.cpp)
add_executable(977 leetcode/977.cpp)
add_executable(209 leetcode/209.cpp)
add_executable(904 leetcode/904.cpp)
add_executable(76 leetcode/76.cpp)
add_executable(59 leetcode/59.cpp)
add_executable(54 leetcode/54.cpp)
add_executable(203 leetcode/203.cpp)
add_executable(707 leetcode/707.cpp)
add_executable(206 leetcode/206.cpp)
add_executable(24 leetcode/24.cpp)
add_executable(19 leetcode/19.cpp)
add_executable(160 leetcode/160.cpp)
add_executable(142 leetcode/142.cpp)
add_executable(242 leetcode/242.cpp)
add_executable(383 leetcode/383.cpp)
add_executable(49 leetcode/49.cpp)
add_executable(438 leetcode/438.cpp)
add_executable(349 leetcode/349.cpp)
add_executable(350 leetcode/350.cpp)
add_executable(202 leetcode/202.cpp)
add_executable(454 leetcode/454.cpp)
add_executable(15 leetcode/15.cpp)
add_executable(18 leetcode/18.cpp)
add_executable(344 leetcode/344.cpp)
add_executable(541 leetcode/541.cpp)
add_executable(05 sword_offer/05.cpp
        leetcode/1726.cpp)
add_executable(151 leetcode/151.cpp)
add_executable(58 sword_offer2/58.cpp)
add_executable(28 leetcode/28.cpp)
add_executable(KMP extra_algorithm/KMP.cpp)
add_executable(459 leetcode/459.cpp)
add_executable(232 leetcode/232.cpp)
add_executable(225 leetcode/225.cpp)
add_executable(20 leetcode/20.cpp)
add_executable(1047 leetcode/1047.cpp)
add_executable(150 leetcode/150.cpp)
add_executable(239 leetcode/239.cpp)
add_executable(347 leetcode/347.cpp)
add_executable(144 leetcode/144.cpp)
add_executable(94 leetcode/94.cpp)
add_executable(145 leetcode/145.cpp)
add_executable(three_order_walk_tree extra_algorithm/three_order_walk_tree.cpp)
add_executable(102 leetcode/102.cpp)
add_executable(109 leetcode/109.cpp)
add_executable(199 leetcode/199.cpp)
add_executable(637 leetcode/637.cpp)
add_executable(429 leetcode/429.cpp)
add_executable(515 leetcode/515.cpp)
add_executable(116 leetcode/116.cpp)
add_executable(117 leetcode/117.cpp)
add_executable(104 leetcode/104.cpp)
add_executable(111 leetcode/111.cpp)
add_executable(226 leetcode/226.cpp)
add_executable(589 leetcode/589.cpp)
add_executable(590 leetcode/590.cpp)
add_executable(101 leetcode/101.cpp)
add_executable(735 leetcode/735.cpp)
add_executable(100 leetcode/100.cpp)
add_executable(572 leetcode/572.cpp)
add_executable(559 leetcode/559.cpp)
add_executable(222 leetcode/222.cpp)
add_executable(110 leetcode/110.cpp)
add_executable(257 leetcode/257.cpp)
add_executable(404 leetcode/404.cpp)
add_executable(513 leetcode/513.cpp)
add_executable(41 leetcode/41.cpp)
add_executable(112 leetcode/112.cpp)
add_executable(113 leetcode/113.cpp)
add_executable(106 leetcode/106.cpp)
add_executable(105 leetcode/105.cpp)
add_executable(654 leetcode/654.cpp)
add_executable(739 leetcode/739.cpp)
add_executable(617 leetcode/617.cpp)
add_executable(700 leetcode/700.cpp)
add_executable(98 leetcode/98.cpp)
add_executable(530 leetcode/530.cpp)
add_executable(501 leetcode/501.cpp)
add_executable(236 leetcode/236.cpp)
add_executable(235 leetcode/235.cpp)
add_executable(701 leetcode/701.cpp)
add_executable(450 leetcode/450.cpp)
add_executable(66 leetcode/66.cpp)
add_executable(669 leetcode/669.cpp)
add_executable(108 leetcode/108.cpp)
add_executable(538 leetcode/538.cpp)
add_executable(455 leetcode/455.cpp)
add_executable(77 leetcode/77.cpp)
add_executable(216 leetcode/216.cpp)
add_executable(17 leetcode/17.cpp)
add_executable(39 leetcode/39.cpp)
add_executable(40 leetcode/40.cpp)
add_executable(131 leetcode/131.cpp)
add_executable(93 leetcode/93.cpp)
add_executable(78 leetcode/78.cpp)
add_executable(90 leetcode/90.cpp)
add_executable(491 leetcode/491.cpp)
add_executable(46 leetcode/46.cpp)
add_executable(47 leetcode/47.cpp)
add_executable(332 leetcode/332.cpp)
add_executable(53 leetcode/53.cpp)
add_executable(376 leetcode/376.cpp)
add_executable(122 leetcode/122.cpp)
add_executable(55 leetcode/55.cpp)
add_executable(45 leetcode/45.cpp)
add_executable(1005 leetcode/1005.cpp)
add_executable(134 leetcode/134.cpp)
add_executable(135 leetcode/135.cpp)
add_executable(320_1 single_week/320_1_6241.cpp)
add_executable(320_2_6242 single_week/320_2_6242.cpp)
add_executable(51 leetcode/51.cpp)
add_executable(37 leetcode/37.cpp)
add_executable(860 leetcode/860.cpp)
add_executable(406 leetcode/406.cpp)
add_executable(452 leetcode/452.cpp)
add_executable(435 leetcode/435.cpp)
add_executable(763 leetcode/763.cpp)
add_executable(56 leetcode/56.cpp)
add_executable(738 leetcode/738.cpp)
add_executable(795 leetcode/795.cpp)
add_executable(714 leetcode/714.cpp)
add_executable(809 leetcode/809.cpp)
add_executable(509 leetcode/509.cpp)
add_executable(topsort 9/topsort.cpp)
add_executable(unweighted 9/unweighted.cpp)
add_executable(dijkstra 9/dijkstra.cpp)
add_executable(882 leetcode/882.cpp)
add_executable(92_1_6249 double_week/92_1_6249.cpp)
add_executable(92_2_6277 double_week/92_2_6277.cpp)
add_executable(92_3_6250 double_week/92_3_6250.cpp)
add_executable(92_4_6251 double_week/92_4_6251.cpp)
add_executable(321_1_6245 single_week/321_1_6245.cpp)
add_executable(321_2_6246 single_week/321_2_6246.cpp)
add_executable(321_3_6247 single_week/321_3_6247.cpp)
add_executable(321_4_6248 single_week/321_4_6248.cpp)
add_executable(1752 leetcode/1752.cpp)
add_executable(813 leetcode/813.cpp)
add_executable(1758 leetcode/1758.cpp)
add_executable(895 leetcode/895.cpp)
add_executable(1779 leetcode/1779.cpp)
add_executable(322_4 single_week/322_4.cpp)
add_executable(322_1 single_week/322_1.cpp)
add_executable(322_2 single_week/322_2.cpp)
add_executable(322_3 single_week/322_3.cpp)
add_executable(1769 leetcode/1769.cpp)
add_executable(70 leetcode/70.cpp)
add_executable(746 leetcode/746.cpp)
add_executable(62 leetcode/62.cpp)
add_executable(63 leetcode/63.cpp)
add_executable(1796 leetcode/1796.cpp)
add_executable(1774 leetcode/1774.cpp)
add_executable(96 leetcode/96.cpp)
add_executable(1805 leetcode/1805.cpp)
add_executable(416 leetcode/416.cpp)
add_executable(698 leetcode/698.cpp)
add_executable(1775 leetcode/1775.cpp)
add_executable(1812 leetcode/1812.cpp)
add_executable(1049 leetcode/1049.cpp)
add_executable(494 leetcode/494.cpp)
add_executable(474 leetcode/474.cpp)
add_executable(1780 leetcode/1780.cpp)
add_executable(93_4 double_week/93_4.cpp)
add_executable(93_3 double_week/93_3.cpp)
add_executable(93_2 double_week/93_2.cpp)
add_executable(93_1 double_week/93_1.cpp)
add_executable(323_1 single_week/323_1.cpp)
add_executable(323_4 single_week/323_4.cpp)
add_executable(323_3 single_week/323_3.cpp)
add_executable(323_2 single_week/323_2.cpp)
add_executable(968 leetcode/968.cpp)
add_executable(s30 sword_offer/s30.cpp)
add_executable(1691 leetcode/1691.cpp)
add_executable(1827 leetcode/1827.cpp)
add_executable(s09 sword_offer/s09.cpp)
add_executable(1781 leetcode/1781.cpp)
add_executable(518 leetcode/518.cpp)
add_executable(377 leetcode/377.cpp)
add_executable(1832 leetcode/1832.cpp)
add_executable(1697 leetcode/1697.cpp)
add_executable(79 leetcode/79.cpp)
add_executable(1945 leetcode/1945.cpp)
add_executable(300 leetcode/300.cpp)
add_executable(1785 leetcode/1785.cpp)
add_executable(354 leetcode/354.cpp)
add_executable(322 leetcode/322.cpp)
add_executable(279 leetcode/279.cpp)
add_executable(2342 leetcode/2342.cpp)
add_executable(1971 leetcode/1971.cpp)
add_executable(95 leetcode/95.cpp)