project('lithium', 'cpp', 'c', 'nasm')

linker_scripts = {
    'x86_64': '../src/arch/x86_64/linker.ld',
    'aarch64': '../src/arch/aarch64/linker.ld'
}

cargs = ['-std=c99',
    '-ffreestanding',
    '-fno-stack-protector',
    '-fno-stack-check',
    '-fno-lto',
    '-fno-pie',
    '-fno-pic',
    '-mcmodel=kernel',
    '-nostdinc']

cppargs = ['-ffreestanding',
    '-fno-stack-protector',
    '-fno-stack-check',
    '-fno-lto',
    '-fno-pie',
    '-fno-pic',
    '-mcmodel=kernel',
    '-nostdinc']

arch = get_option('arch')

ldargs = ['-nostdlib',
    '-static',
    '-T', linker_scripts[arch]]

src = ['src/kmain.cpp', 
    'src/term/flanterm.c', 
    'src/term/backends/fb.c', 
    'src/term/term.cpp',
    'src/libc/string.c',
    'src/utils/panic.cpp']

if arch == 'x86_64'
    src += ['src/arch/x86_64/init.cpp',
    'src/arch/x86_64/gdt.cpp',
    'src/arch/x86_64/asm/gdt.asm',
    'src/arch/x86_64/asm/idt.asm',
    'src/arch/x86_64/asm/isr.asm',
    'src/arch/x86_64/idt.cpp',
    'src/arch/x86_64/isr.cpp']
endif

if arch == 'aarch64'
    src += ['src/arch/aarch64/init.cpp']
endif

include_dirs = ['src/include', 'src/include/libc']

executable('kernel.elf', src,
    include_directories: include_dirs,
    c_args: cargs,
    cpp_args: cppargs,
    link_args: ldargs,
    nasm_args: ['-felf64']
)