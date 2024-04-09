
// File auto-generated by Padrick unknown
module carfield_padframe_behav_periph
  import pkg_carfield_padframe_behav::*;
  import pkg_internal_carfield_padframe_behav_periph::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
  output pad_domain_periph_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
  input pad_domain_periph_static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
  output pad_domain_periph_ports_pad2soc_t port_signals_pad2soc_o,
  input pad_domain_periph_ports_soc2pad_t port_signals_soc2pad_i,
  inout wire logic pad_reset_n_pad,
  inout wire logic pad_bypass_fll_pad,
  inout wire logic pad_ref_clk_pad,
  inout wire logic pad_ext_clk_pad,
  inout wire logic pad_secure_boot_pad,
  inout wire logic pad_bootmode_host_0_pad,
  inout wire logic pad_bootmode_host_1_pad,
  inout wire logic pad_bootmode_host_2_pad,
  inout wire logic pad_jtag_host_tck_pad,
  inout wire logic pad_jtag_host_tms_pad,
  inout wire logic pad_jtag_host_tdi_pad,
  inout wire logic pad_jtag_host_trstn_pad,
  inout wire logic pad_jtag_host_tdo_pad,
  inout wire logic pad_host_00_pad,
  inout wire logic pad_host_01_pad,
  inout wire logic pad_host_02_pad,
  inout wire logic pad_host_03_pad,
  inout wire logic pad_host_04_pad,
  inout wire logic pad_host_05_pad,
  inout wire logic pad_host_06_pad,
  inout wire logic pad_host_07_pad,
  inout wire logic pad_host_08_pad,
  inout wire logic pad_host_09_pad,
  inout wire logic pad_host_10_pad,
  inout wire logic pad_bootmode_safe_0_pad,
  inout wire logic pad_bootmode_safe_1_pad,
  inout wire logic pad_jtag_safe_tck_pad,
  inout wire logic pad_jtag_safe_tms_pad,
  inout wire logic pad_jtag_safe_tdi_pad,
  inout wire logic pad_jtag_safe_trstn_pad,
  inout wire logic pad_jtag_safe_tdo_pad,
  inout wire logic pad_bootmode_secure_0_pad,
  inout wire logic pad_bootmode_secure_1_pad,
  inout wire logic pad_jtag_secure_tck_pad,
  inout wire logic pad_jtag_secure_tms_pad,
  inout wire logic pad_jtag_secure_tdi_pad,
  inout wire logic pad_jtag_secure_trstn_pad,
  inout wire logic pad_jtag_secure_tdo_pad,
  inout wire logic pad_secure_00_pad,
  inout wire logic pad_secure_01_pad,
  inout wire logic pad_secure_02_pad,
  inout wire logic pad_secure_03_pad,
  inout wire logic pad_secure_04_pad,
  inout wire logic pad_secure_05_pad,
  inout wire logic pad_secure_06_pad,
  inout wire logic pad_secure_07_pad,
  inout wire logic pad_gpio_00_pad,
  inout wire logic pad_gpio_01_pad,
  inout wire logic pad_gpio_02_pad,
  inout wire logic pad_gpio_03_pad,
  inout wire logic pad_gpio_04_pad,
  inout wire logic pad_gpio_05_pad,
  inout wire logic pad_gpio_06_pad,
  inout wire logic pad_gpio_07_pad,
  inout wire logic pad_gpio_08_pad,
  inout wire logic pad_gpio_09_pad,
  inout wire logic pad_gpio_10_pad,
  inout wire logic pad_gpio_11_pad,
  inout wire logic pad_gpio_12_pad,
  inout wire logic pad_gpio_13_pad,
  inout wire logic pad_gpio_14_pad,
  inout wire logic pad_gpio_15_pad,
  inout wire logic pad_periph_00_pad,
  inout wire logic pad_periph_01_pad,
  inout wire logic pad_periph_02_pad,
  inout wire logic pad_periph_03_pad,
  inout wire logic pad_periph_04_pad,
  inout wire logic pad_periph_05_pad,
  inout wire logic pad_periph_06_pad,
  inout wire logic pad_periph_07_pad,
  inout wire logic pad_periph_08_pad,
  inout wire logic pad_periph_09_pad,
  inout wire logic pad_periph_10_pad,
  inout wire logic pad_periph_11_pad,
  inout wire logic pad_periph_12_pad,
  inout wire logic pad_periph_13_pad,
  inout wire logic pad_periph_14_pad,
  inout wire logic pad_periph_15_pad,
  inout wire logic pad_periph_16_pad,
  inout wire logic pad_hyper0_csn0_pad,
  inout wire logic pad_hyper0_csn1_pad,
  inout wire logic pad_hyper0_ck_pad,
  inout wire logic pad_hyper0_ckn_pad,
  inout wire logic pad_hyper0_rwds_pad,
  inout wire logic pad_hyper0_rstn_pad,
  inout wire logic pad_hyper0_data0_pad,
  inout wire logic pad_hyper0_data1_pad,
  inout wire logic pad_hyper0_data2_pad,
  inout wire logic pad_hyper0_data3_pad,
  inout wire logic pad_hyper0_data4_pad,
  inout wire logic pad_hyper0_data5_pad,
  inout wire logic pad_hyper0_data6_pad,
  inout wire logic pad_hyper0_data7_pad,
  inout wire logic pad_hyper1_csn0_pad,
  inout wire logic pad_hyper1_csn1_pad,
  inout wire logic pad_hyper1_ck_pad,
  inout wire logic pad_hyper1_ckn_pad,
  inout wire logic pad_hyper1_rwds_pad,
  inout wire logic pad_hyper1_rstn_pad,
  inout wire logic pad_hyper1_data0_pad,
  inout wire logic pad_hyper1_data1_pad,
  inout wire logic pad_hyper1_data2_pad,
  inout wire logic pad_hyper1_data3_pad,
  inout wire logic pad_hyper1_data4_pad,
  inout wire logic pad_hyper1_data5_pad,
  inout wire logic pad_hyper1_data6_pad,
  inout wire logic pad_hyper1_data7_pad,
  inout wire logic pad_sl_clk_in_pad,
  inout wire logic pad_sl_data_in0_pad,
  inout wire logic pad_sl_data_in1_pad,
  inout wire logic pad_sl_data_in2_pad,
  inout wire logic pad_sl_data_in3_pad,
  inout wire logic pad_sl_data_in4_pad,
  inout wire logic pad_sl_data_in5_pad,
  inout wire logic pad_sl_data_in6_pad,
  inout wire logic pad_sl_data_in7_pad,
  inout wire logic pad_sl_clk_out_pad,
  inout wire logic pad_sl_data_out0_pad,
  inout wire logic pad_sl_data_out1_pad,
  inout wire logic pad_sl_data_out2_pad,
  inout wire logic pad_sl_data_out3_pad,
  inout wire logic pad_sl_data_out4_pad,
  inout wire logic pad_sl_data_out5_pad,
  inout wire logic pad_sl_data_out6_pad,
  inout wire logic pad_sl_data_out7_pad,
  inout wire logic pad_debug_out0_pad,
  inout wire logic pad_debug_out1_pad,
  inout wire logic pad_debug_out2_pad,
  inout wire logic pad_debug_out3_pad,
  inout wire logic pad_debug_out4_pad,
  inout wire logic pad_jtag_pll_00_pad,
  inout wire logic pad_jtag_pll_01_pad,
  inout wire logic pad_jtag_pll_02_pad,
  inout wire logic pad_jtag_pll_03_pad,
  inout wire logic pad_jtag_pll_04_pad,
  input req_t config_req_i,
  output resp_t config_rsp_o
);

   mux_to_pads_t s_mux_to_pads;
   pads_to_mux_t s_pads_to_mux;

   carfield_padframe_behav_periph_pads i_periph_pads (
     .static_connection_signals_pad2soc,
     .static_connection_signals_soc2pad,
     .mux_to_pads_i(s_mux_to_pads),
     .pads_to_mux_o(s_pads_to_mux),
     .pad_reset_n_pad,
     .pad_bypass_fll_pad,
     .pad_ref_clk_pad,
     .pad_ext_clk_pad,
     .pad_secure_boot_pad,
     .pad_bootmode_host_0_pad,
     .pad_bootmode_host_1_pad,
     .pad_bootmode_host_2_pad,
     .pad_jtag_host_tck_pad,
     .pad_jtag_host_tms_pad,
     .pad_jtag_host_tdi_pad,
     .pad_jtag_host_trstn_pad,
     .pad_jtag_host_tdo_pad,
     .pad_host_00_pad,
     .pad_host_01_pad,
     .pad_host_02_pad,
     .pad_host_03_pad,
     .pad_host_04_pad,
     .pad_host_05_pad,
     .pad_host_06_pad,
     .pad_host_07_pad,
     .pad_host_08_pad,
     .pad_host_09_pad,
     .pad_host_10_pad,
     .pad_bootmode_safe_0_pad,
     .pad_bootmode_safe_1_pad,
     .pad_jtag_safe_tck_pad,
     .pad_jtag_safe_tms_pad,
     .pad_jtag_safe_tdi_pad,
     .pad_jtag_safe_trstn_pad,
     .pad_jtag_safe_tdo_pad,
     .pad_bootmode_secure_0_pad,
     .pad_bootmode_secure_1_pad,
     .pad_jtag_secure_tck_pad,
     .pad_jtag_secure_tms_pad,
     .pad_jtag_secure_tdi_pad,
     .pad_jtag_secure_trstn_pad,
     .pad_jtag_secure_tdo_pad,
     .pad_secure_00_pad,
     .pad_secure_01_pad,
     .pad_secure_02_pad,
     .pad_secure_03_pad,
     .pad_secure_04_pad,
     .pad_secure_05_pad,
     .pad_secure_06_pad,
     .pad_secure_07_pad,
     .pad_gpio_00_pad,
     .pad_gpio_01_pad,
     .pad_gpio_02_pad,
     .pad_gpio_03_pad,
     .pad_gpio_04_pad,
     .pad_gpio_05_pad,
     .pad_gpio_06_pad,
     .pad_gpio_07_pad,
     .pad_gpio_08_pad,
     .pad_gpio_09_pad,
     .pad_gpio_10_pad,
     .pad_gpio_11_pad,
     .pad_gpio_12_pad,
     .pad_gpio_13_pad,
     .pad_gpio_14_pad,
     .pad_gpio_15_pad,
     .pad_periph_00_pad,
     .pad_periph_01_pad,
     .pad_periph_02_pad,
     .pad_periph_03_pad,
     .pad_periph_04_pad,
     .pad_periph_05_pad,
     .pad_periph_06_pad,
     .pad_periph_07_pad,
     .pad_periph_08_pad,
     .pad_periph_09_pad,
     .pad_periph_10_pad,
     .pad_periph_11_pad,
     .pad_periph_12_pad,
     .pad_periph_13_pad,
     .pad_periph_14_pad,
     .pad_periph_15_pad,
     .pad_periph_16_pad,
     .pad_hyper0_csn0_pad,
     .pad_hyper0_csn1_pad,
     .pad_hyper0_ck_pad,
     .pad_hyper0_ckn_pad,
     .pad_hyper0_rwds_pad,
     .pad_hyper0_rstn_pad,
     .pad_hyper0_data0_pad,
     .pad_hyper0_data1_pad,
     .pad_hyper0_data2_pad,
     .pad_hyper0_data3_pad,
     .pad_hyper0_data4_pad,
     .pad_hyper0_data5_pad,
     .pad_hyper0_data6_pad,
     .pad_hyper0_data7_pad,
     .pad_hyper1_csn0_pad,
     .pad_hyper1_csn1_pad,
     .pad_hyper1_ck_pad,
     .pad_hyper1_ckn_pad,
     .pad_hyper1_rwds_pad,
     .pad_hyper1_rstn_pad,
     .pad_hyper1_data0_pad,
     .pad_hyper1_data1_pad,
     .pad_hyper1_data2_pad,
     .pad_hyper1_data3_pad,
     .pad_hyper1_data4_pad,
     .pad_hyper1_data5_pad,
     .pad_hyper1_data6_pad,
     .pad_hyper1_data7_pad,
     .pad_sl_clk_in_pad,
     .pad_sl_data_in0_pad,
     .pad_sl_data_in1_pad,
     .pad_sl_data_in2_pad,
     .pad_sl_data_in3_pad,
     .pad_sl_data_in4_pad,
     .pad_sl_data_in5_pad,
     .pad_sl_data_in6_pad,
     .pad_sl_data_in7_pad,
     .pad_sl_clk_out_pad,
     .pad_sl_data_out0_pad,
     .pad_sl_data_out1_pad,
     .pad_sl_data_out2_pad,
     .pad_sl_data_out3_pad,
     .pad_sl_data_out4_pad,
     .pad_sl_data_out5_pad,
     .pad_sl_data_out6_pad,
     .pad_sl_data_out7_pad,
     .pad_debug_out0_pad,
     .pad_debug_out1_pad,
     .pad_debug_out2_pad,
     .pad_debug_out3_pad,
     .pad_debug_out4_pad,
     .pad_jtag_pll_00_pad,
     .pad_jtag_pll_01_pad,
     .pad_jtag_pll_02_pad,
     .pad_jtag_pll_03_pad,
     .pad_jtag_pll_04_pad

  );

   carfield_padframe_behav_periph_muxer #(
     .req_t(req_t),
     .resp_t(resp_t)
   )i_periph_muxer (
     .clk_i,
     .rst_ni,
     .port_signals_soc2pad_i,
     .port_signals_pad2soc_o,
     .mux_to_pads_o(s_mux_to_pads),
     .pads_to_mux_i(s_pads_to_mux),
     // Configuration interface using register_interface protocol
     .config_req_i,
     .config_rsp_o
   );

endmodule : carfield_padframe_behav_periph
