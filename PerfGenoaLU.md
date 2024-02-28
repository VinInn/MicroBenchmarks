---++ data/PerfGenoaLU
| |  LUv1w1 | LUv1w128 | LUv2w128 | LUv3w256 | LUv4w1 | LUv4w128 | LUv4w256 | LUv4w512 ||
|duration |  8414.0000 |  6977.0000 |  7057.0000 |  4342.0000 |  7808.0000 |  7148.0000 |  3885.0000 |  4086.0000 | |
|task-clock |  8448.0400 |  7011.5800 |  7088.3500 |  4370.5100 |  7836.9200 |  7173.1500 |  3908.7700 |  4109.9800 | |
|cycles |  31.8479 |  26.4209 |  26.7215 |  16.4649 |  29.5442 |  27.0393 |  14.7463 |  15.4717 | |
|stalled-cycles-backend |  0.0056 |  0.0052 |  0.0058 |  0.0049 |  0.0112 |  0.0044 |  0.0124 |  0.0021 | |
|stalled-cycles-frontend |  0.0091 |  0.0148 |  0.0140 |  0.0152 |  0.0101 |  0.0135 |  0.0104 |  0.0297 | |
|iTLB-load-misses |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|iTLB-loads |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|instructions |  183.2240 |  92.4185 |  92.6257 |  35.8211 |  137.9965 |  68.9957 |  35.7430 |  19.3165 | |
|branch-instructions |  22.9173 |  11.5962 |  11.6238 |  5.9721 |  22.9982 |  11.5305 |  5.9656 |  3.1743 | |
|branch-misses |  0.0334 |  0.0236 |  0.0226 |  0.0062 |  0.0336 |  0.0208 |  0.0023 |  0.0019 | |
|ex_ret_instr |  183.2996 |  92.4945 |  92.4675 |  35.9178 |  138.3062 |  69.7186 |  36.0996 |  19.3640 | |
|ex_ret_ops |  160.6362 |  81.1295 |  81.0106 |  30.0752 |  115.4214 |  58.6725 |  30.2625 |  18.9699 | |
|ex_no_retire.all |  8.3802 |  10.2515 |  10.5851 |  11.4582 |  12.9354 |  13.6788 |  10.1448 |  12.7288 | |
|ex_div_busy |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|sse_avx_ops_retired.all |  68.6837 |  34.5032 |  34.5280 |  11.6826 |  46.0264 |  23.1955 |  11.7256 |  8.9169 | |
|sse_avx_ops_retired.sse_avx_other |  68.6945 |  34.4639 |  34.5122 |  11.6698 |  46.0331 |  23.1355 |  11.6598 |  8.8611 | |
|sse_avx_ops_retired.sse_avx_shuffle |  0.0000 |  0.0336 |  0.0334 |  0.0168 |  0.0000 |  0.0329 |  0.0168 |  0.0000 | |
|sse_avx_ops_retired.sse_avx_mov |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0001 |  0.0336 |  0.0668 | |
|sse_avx_ops_retired.sse_avx_logical |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|sse_avx_ops_retired.sse_avx_shift |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|packed_int_op_type.int128_mov |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0001 |  0.0336 |  0.0662 | |
|packed_int_op_type.int256_mov |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|packed_int_op_type.all |  68.9888 |  34.6347 |  34.0188 |  11.6113 |  45.8341 |  22.8538 |  11.6728 |  0.3316 | |
|fp_ret_sse_avx_ops.all |  45.8883 |  45.9097 |  44.9302 |  45.7630 |  45.6635 |  45.5766 |  45.8900 |  45.9454 | |
|fp_ret_sse_avx_ops.add_sub_flops |  22.9619 |  22.9367 |  22.8653 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|fp_ret_sse_avx_ops.mult_flops |  22.9673 |  22.9269 |  22.9846 |  0.0339 |  0.0336 |  0.0314 |  0.0341 |  0.0338 | |
|fp_ret_sse_avx_ops.mac_flops |  0.0000 |  0.0000 |  0.0000 |  45.5534 |  45.5968 |  46.2257 |  45.7203 |  45.6128 | |
|fp_ret_sse_avx_ops.div_flops |  0.0001 |  0.0001 |  0.0001 |  0.0001 |  0.0001 |  0.0000 |  0.0001 |  0.0001 | |
|fp_ops_retired_by_width.all |  115.0189 |  57.7473 |  57.8254 |  17.6046 |  68.6629 |  34.8748 |  17.5886 |  11.9668 | |
|fp_ops_retired_by_width.mmx_uops_retired |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 | |
|fp_ops_retired_by_width.pack_128_uops_retired |  69.0421 |  57.5828 |  57.6435 |  0.2669 |  45.8144 |  34.7049 |  0.3013 |  0.3419 | |
|fp_ops_retired_by_width.pack_256_uops_retired |  0.0000 |  0.0000 |  0.0000 |  17.1163 |  0.0000 |  0.0000 |  17.2013 |  0.0687 | |
|fp_ops_retired_by_width.pack_512_uops_retired |  0.0245 |  0.0231 |  0.0232 |  0.0264 |  0.0237 |  0.0000 |  0.0250 |  11.4204 | |
|fp_ops_retired_by_width.scalar_uops_retired |  45.9162 |  0.1354 |  0.1349 |  0.1174 |  22.9915 |  0.1247 |  0.1172 |  0.1535 | |
|cache-misses |  0.3359 |  0.3710 |  0.3598 |  0.6493 |  0.2615 |  0.3488 |  0.7144 |  0.8423 | |
|cache-references |  8.7355 |  9.1687 |  9.0146 |  8.0008 |  8.5974 |  9.0905 |  7.6742 |  7.7759 | |
|all_data_cache_accesses |  69.6313 |  35.0760 |  35.1420 |  17.9322 |  69.7967 |  34.7642 |  17.9748 |  12.3523 | |
|L1-dcache-load-misses |  3.5161 |  3.5960 |  3.6278 |  3.6223 |  3.3710 |  3.6702 |  3.4833 |  3.5367 | |
|L1-dcache-loads |  69.1910 |  39.3177 |  39.4313 |  24.5547 |  69.1176 |  39.2945 |  24.5402 |  20.3044 | |
|L1-dcache-prefetches |  1.6680 |  2.3568 |  2.4123 |  1.5217 |  0.2625 |  2.2889 |  0.3235 |  0.5564 | |
|L1-icache-load-misses |  0.0001 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0001 | |
|L1-icache-loads |  0.0303 |  0.0283 |  0.0344 |  0.0303 |  0.0217 |  0.0278 |  0.0264 |  0.0417 | |
|dTLB-load-misses |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0000 |  0.0001 |  0.0000 | |
|dTLB-loads |  0.0372 |  0.0372 |  0.0372 |  0.0374 |  0.0372 |  0.0374 |  0.0374 |  0.0370 | |
