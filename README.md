# Lithium Kernel

## Build Instructions
<code lang="sh">
meson setup build -Darch=x86_64 --cross-file x86_64.txt<br>
ninja -C build<br>
</code>

### Extra: For a runnable iso
<code lang="sh">
python -m makeiso<br>
</code>