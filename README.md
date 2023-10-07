<!--
    =====================================
    generator=datazen
    version=3.1.4
    hash=06344b757411ea1a4ce3d80d70172a2b
    =====================================
-->

# xmc ([0.1.1](https://github.com/vkottler/xmc/releases/tag/0.1.1))

[![codecov](https://codecov.io/gh/vkottler/xmc/branch/master/graph/badge.svg)](https://codecov.io/gh/vkottler/xmc)
![Build Status](https://github.com/vkottler/xmc/actions/workflows/yambs-project.yml/badge.svg)

*A firmware project for Infineon XMC devices.*

## Workflow

Install [vmklib](https://github.com/vkottler/vmklib) such that you can
`mk --version` (a `pip install vmklib` to your desired Python environment is
all that's needed).

From a fresh checkout:

```
git submodule update --init
mk dz-sync
mk download-toolchains
mk g
```

This should result in fully compiled code that you can now use or add to.
