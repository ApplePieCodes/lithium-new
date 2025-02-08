project('lithium', 'c')

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
    '-mcmodel=kernel']

arch = get_option('arch')

ldargs = ['-nostdlib',
    '-static',
    '-T', linker_scripts[arch]]

src = ['src/kmain.c']

if arch == 'x86_64'
    src += ['src/arch/x86_64/init.c']
endif

if arch == 'aarch64'
    src += ['src/arch/aarch64/init.c']
endif

executable('kernel', src,
    include_directories: ['src/include'],
    c_args: cargs,
    link_args: ldargs
)