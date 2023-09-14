# mP-RPC
## muduo and Protobuf based Remote Procedure Call Library


Before compiling this project, you should install muduo and zookeeper first.

### Install muduo
```shell
git clone https://github.com/chenshuo/muduo.git
cd muduo
sudo ./build.sh install
cd ../build/release-install-cpp11
sudo cp -r include/* /usr/local/include
sudo cp -r lib/* /usr/local/lib
```

----

### Install zookeeper(in directory of this project)
it may cause compile error. If that happens, please remove string `"-Werror"` in `/zookeeper-3.4.10/src/c/Makefile`

```shell
#start zookeeper service locally
#Please ensure that port 2181 is not in use
cd zookeeper-3.4.10/bin
./zkServer.sh start

## install native API of zookeeper
cd zookeeper-3.4.10/src/c
sudo ./configure
sudo make
sudo make install
```
----

### Genrating static link library only.

```shell
cmake -S . -B build
cmake --build build
```
----

### Automated shell script to compile ``mprpc`` and example applications
```shell
chmod +x autobuild.sh
sudo ./autobuild.sh
```

----

### Run provider and consumer (simple applications of ``mprpc`` library)

```shell
cd bin
./provider -i test.conf
./consumer -i test.conf
```

