// AM335x ARM® Cortex™-A8 Microprocessors (MPUs) Technical Reference Manual

typedef uint16_t volatile * reg16_p;
reg16_p reg16 (uintptr_t address)
{
	return reinterpret_cast <reg16_p> (address);
}

typedef uint32_t volatile * reg32_p;
reg32_p reg32 (uintptr_t address)
{
	return reinterpret_cast <reg32_p> (address);
}

class arm33x_prm
{
public:
	arm33x_prm (uintptr_t base_a) :
	base (base_a)
	{
	}
	reg32_p revision ()
	{
		return reg32 (base + 0x00);
	}
	reg32_p irqstatus_mpu ()
	{
		return reg32 (base + 0x04);
	}
	reg32_p irqenable_mpu ()
	{
		return reg32 (base + 0x08);
	}
	reg32_p irqstatus_m3 ()
	{
		return reg32 (base + 0x0c);
	}
	reg32_p irqenable_m3 ()
	{
		return reg32 (base + 0x10);
	}
	uintptr_t base;
};

class arm33x_tsc_adc
{
public:
	arm33x_tsc_adc (uintptr_t base_a) :
	base (base_a)
	{
	}
	reg32_p revision ()
	{
		return reg32 (base + 0x00);
	}
	reg32_p irqstatus_raw ()
	{
		return reg32 (base + 0x24);
	}
	reg32_p irqstatus ()
	{
		return reg32 (base + 0x28);
	}
	reg32_p irqenable_clr ()
	{
		return reg32 (base + 0x30);
	}
	reg32_p ctrl ()
	{
		return reg32 (base + 0x40);
	}
	reg32_p range ()
	{
		return reg32 (base + 0x48);
	}
	reg32_p stepenable ()
	{
		return reg32 (base + 0x54);
	}
	reg32_p stepconfig1 ()
	{
		return reg32 (base + 0x64);
	}
	reg32_p stepdelay1 ()
	{
		return reg32 (base + 0x68);
	}
	reg32_p fifo0count ()
	{
		return reg32 (base + 0xe4);
	}
	reg32_p fifo0threshold ()
	{
		return reg32 (base + 0xe8);
	}
	reg32_p fifo0data ()
	{
		return reg32 (base + 0x100);
	}
	static uint32_t constexpr fifo0 = 0x0;
	static uint32_t constexpr average0 = 0x0;
	static uint32_t constexpr oneshot = 0x0;
	uintptr_t base;
};

class arm33x_wkup
{
public:
	arm33x_wkup (uintptr_t base_a):
	base (base_a)
	{
	}
	reg32_p cm_wkup_clkstctrl ()
	{
		return reg32 (base + 0x00);
	}
	reg32_p cm_wkup_adc_tsc_clkctrl ()
	{
		return reg32 (base + 0xbc);
	}
	void enable_tsc_adc_clock ()
	{
		*cm_wkup_adc_tsc_clkctrl () = adc_tsc_clkctrl_modulemode_enable;
	}
	static uint32_t constexpr adc_tsc_clkctrl_modulemode_enable = 0x00000002;
	uintptr_t base;
};

class arm33x_gpio
{
public:
	arm33x_gpio (uintptr_t base_a):
	base (base_a)
	{
	}
	reg32_p oe ()
	{
		return reg32 (base + 0x134);
	}
	reg32_p clear_data_out ()
	{
		return reg32 (base + 0x190);
	}
	reg32_p set_data_out ()
	{
		return reg32 (base + 0x194);
	}
	uintptr_t base;
};

class arm33x_epwm
{
public:
	arm33x_epwm (uintptr_t base_a) :
	base (base_a)
	{
	}
	reg16_p tbctl ()
	{
		return reg16 (base + 0x00);
	}
	reg16_p tbsts ()
	{
		return reg16 (base + 0x02);
	}
	reg16_p tbphshr ()
	{
		return reg16 (base + 0x04);
	}
	reg16_p tbphs ()
	{
		return reg16 (base + 0x06);
	}
	reg16_p tbcnt ()
	{
		return reg16 (base + 0x08);
	}
	reg16_p tbprd ()
	{
		return reg16 (base + 0x0a);
	}
	uintptr_t base;
};

class arm33x_pwmss
{
public:
	arm33x_pwmss (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_epwm epwm ()
	{
		return arm33x_epwm (base + 0x200);
	}
	uintptr_t base;
};

enum class arm33x_cm_reg_flags : uint32_t
{
	idlest_func = 0x00000000;
	idlest_trans = 0x00010000;
	idlest_idle = 0x00020000;
	idlest_disable = 0x00030000;
	modulemode_disabled = 0x00000000;
	modulemode_enable = 0x00000002;
};

class arm33x_cm_reg
{
public:
	arm33x_cm_reg (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_cm_reg const & operator = (arm33x_cm_reg_flags flags)
	{
		*reg32 (base) = flags;
	}
	arm33x_cm_reg operator * ()
	{
		return *reg32 (base);
	}
	void enable ()
	{
		(*this) = arm33x_cm_reg_flags.modulemode_enable;
	}
	uintptr_t base;
}

// 8.1.12 Clock Module Registers
class arm33x_cm_per
{
public:
	arm33x_per (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_cm_reg emif ()
	{
		return arm33x_cm_reg (base + 0x28);
	}
	arm33x_cm_reg ocmcram ()
	{
		return arm33x_cm_reg (base + 0x2c);
	}
	arm33x_cm_reg gpmc ()
	{
		return arm33x_cm_reg (base + 0x30);
	}
	arm33x_cm_reg mcasp0 ()
	{
		return arm33x_cm_reg (base + 0x34);
	}
	arm33x_cm_reg uart5 ()
	{
		return arm33x_cm_reg (base + 0x38);
	}
	arm33x_cm_reg mmc0 ()
	{
		return arm33x_cm_reg (base + 0x3c);
	}
	arm33x_cm_reg elm ()
	{
		return arm33x_cm_reg (base + 0x40);
	}
	arm33x_cm_reg i2c2 ()
	{
		return arm33x_cm_reg (base + 0x44);
	}
	arm33x_cm_reg i2c1 ()
	{
		return arm33x_cm_reg (base + 0x48);
	}
	arm33x_cm_reg spi0 ()
	{
		return arm33x_cm_reg (base + 0x4c);
	}
	arm33x_cm_reg spi1 ()
	{
		return arm33x_cm_reg (base + 0x50);
	}
	arm33x_cm_reg l4ls ()
	{
		return arm33x_cm_reg (base + 0x60);
	}
	arm33x_cm_reg l4fw ()
	{
		return arm33x_cm_reg (base + 0x64);
	}
	arm33x_cm_reg mcasp1 ()
	{
		return arm33x_cm_reg (base + 0x68);
	}
	arm33x_cm_reg uart1 ()
	{
		return arm33x_cm_reg (base + 0x6c);
	}
	arm33x_cm_reg uart2 ()
	{
		return arm33x_cm_reg (base + 0x70);
	}
	arm33x_cm_reg uart3 ()
	{
		return arm33x_cm_reg (base + 0x74);
	}
	arm33x_cm_reg uart4 ()
	{
		return arm33x_cm_reg (base + 0x78);
	}
	arm33x_cm_reg timer7 ()
	{
		return arm33x_cm_reg (base + 0x7c);
	}
	arm33x_cm_reg timer2 ()
	{
		return arm33x_cm_reg (base + 0x80);
	}
	arm33x_cm_reg timer3 ()
	{
		return arm33x_cm_reg (base + 0x84);
	}
	arm33x_cm_reg timer4 ()
	{
		return arm33x_cm_reg (base + 0x88);
	}
	arm33x_cm_reg tpcc ()
	{
		return arm33x_cm_reg (base + 0xbc);
	}
	arm33x_cm_reg dcan0 ()
	{
		return arm33x_cm_reg (base + 0xc0);
	}
	arm33x_cm_reg dcan1 ()
	{
		return arm33x_cm_reg (base + 0xc4);
	}
	arm33x_cm_reg epwmss1 ()
	{
		return arm33x_cm_reg (base + 0xcc);
	}
	arm33x_cm_reg emif_fw ()
	{
		return arm33x_cm_reg (base + 0xd0);
	}
	arm33x_cm_reg epwmss0 ()
	{
		return arm33x_cm_reg (base + 0xd4);
	}
	arm33x_cm_reg epwmss2 ()
	{
		return arm33x_cm_reg (base + 0xd8);
	}
	arm33x_cm_reg l3_instr ()
	{
		return arm33x_cm_reg (base + 0xdc);
	}
	arm33x_cm_reg l3 ()
	{
		return arm33x_cm_reg (base + 0xe0);
	}
	uintptr_t base;
};

// 2.1 ARM Cortex-A8 Memory Map
class arm33x
{
public:
	arm33x ()
	{
		auto fd (open ("/dev/mem", O_RDWR));
		if (fd != -1)
		{
			auto map (mmap (0, mapping_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, mapping_base));
			base = reinterpret_cast <uintptr_t> (map);
			if (map == MAP_FAILED)
			{
				base = 0x0;
			}
		}
		else
		{
			base = 0x0;
		}
	}
	arm33x_pwmss pwm0 ()
	{
		return arm33x_pwmss (base + 0x08300000);
	}
	arm33x_pwmss pwm1 ()
	{
		return arm33x_pwmss (base + 0x08302000);
	}
	arm33x_pwmss pwm2 ()
	{
		return arm33x_pwmss (base + 0x08304000);
	}
	arm33x_prm prm_irq ()
	{
		return arm33x_prm (base + 0x04e00b00);
	}
	arm33x_wkup wkup ()
	{
		return arm33x_wkup (base + 0x04e00400);
	}
	arm33x_per cm_per ()
	{
		return arm33x_cm_per (base + 0x04e00000);
	}
	arm33x_tsc_adc tsc_adc ()
	{
		return arm33x_tsc_adc (base + 0x04e0d000);
	}
	arm33x_gpio gpio0 ()
	{
		return arm33x_gpio (base + 0x04e07000);
	}
	uintptr_t base;
	static uintptr_t constexpr mapping_base = 0x40000000;
	static uintptr_t constexpr mapping_end = 0x58000000;
	static uintptr_t constexpr mapping_size = mapping_end - mapping_base;
};