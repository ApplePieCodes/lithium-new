project('lithium', 'cpp', 'c')

linker_scripts = {
    'x86_64': '../src/arch/x86_64/linker.ld',
    'aarch64': '../src/arch/aarch64/linker.ld'
}

cargs = ['-ffreestanding',
    '-fno-stack-protector',
    '-fno-stack-check',
    '-fno-lto',
    '-fno-pie',
    '-fno-pic',
    '-mcmodel=kernel',
    '-nostdinc',
    '-mno-red-zone']

arch = get_option('arch')

ldargs = ['-nostdlib',
    '-static',
    '-T', linker_scripts[arch]]

src = ['src/kmain.cpp', 
    'src/term/flanterm.c', 
    'src/term/backends/fb.c', 
    'src/term/term.c',
    'src/libc/string.c']

if arch == 'x86_64'
    src += ['src/arch/x86_64/init.cpp', 'src/arch/x86_64/gdt.c']
endif

if arch == 'aarch64'
    src += ['src/arch/aarch64/init.cpp']
endif

include_dirs = ['src/include']

executable('kernel.elf', src,
    include_directories: include_dirs,
    c_args: cargs,
    link_args: ldargs
)