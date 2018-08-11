# SSD_VU9P_verification
西安电子科技大学
刘凯教授科研团队
刘凯
138-9281-0532
kailiu@mail.xidian.eud.cn


FPGA加速深度神经网络
1.使用Winograd算法减少计算量，增加计算的速度，减少片上资源利用。
2.采取8bit的量化方案，使得检测精度损失小于2%。
3.只使用片上资源，不使用DDR等外部资源的辅助，增快计算速度。


版本迭代：
初始版本：将数据从PC端通过PCIE端口传入FPGA内部，由FPGA进行计算，并将得出的最后的结果通过PCIE传出到PC端。由PC端完成结果的显示。
进化版本：通过摄像头实时采集数据，通过cameral Link接口传入FPGA内部，并将得出的最后的结果传入到PC端。

FPGA使用自主研发的基于Winograd算法的CNN架构的资源消耗和功耗状况。
FPGA型号：XCVU9P
处理速度：512x768x3的图可达到25帧/S