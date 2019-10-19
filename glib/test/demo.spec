########################################################
#当定义一个子包时，必须至少包含Summary:,Group:,%description选项
Summary:   Test package for LinuxFly webblog
#必须的
Name:     suite
#必须的
Version:   1.0.0
#必须的
Release:   1
License:   GPL
Group:     System
Source:    demo.tar.gz

########################################################

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
Url:      http://www.linuxfly.org
Packager:  Linuxing
#指定安装的路径
Prefix:    /home/test

%define    user_path /home/a

%description
Just a test rpm suite.

########################################################
#在安装包之前运行 定义准备编译的命令
%prep
echo "---------------------prep"

#---------------------------------------------------
#-c 在解压之前创建子目录 	-q 在安静模式下且最少输出
#-T 禁用自动化解压包     	-i name 设置子目录名字为name
#-D 在解压之前禁止删除目录
#-a number 在改变目录后，仅解压给定数字的源码，如-a 0 for source0
#-b number 在改变目录前，仅解压给定数字的源码，如-b 0 for source0
%setup -c
#-----------------------------------------------------
#编译阶段
%build
echo "---------------------build"
#-------------------------------------------------------
%install
echo "---------------------install"
rm -rf %{buildroot}/*
install -d %{buildroot}/%{user_path}
echo `pwd`
cp -a /home/code/debug/test/install/* %{buildroot}/%{user_path}
#ls -l %{buildroot}/%{user_path}/

cp -a install/* %{buildroot}/
ls -l %{buildroot}
#-----------------------------------------------------
# 安装前执行的脚本，语法和shell脚本的语法相同
%pre
echo "---------------------pre"
#-------------------------------------------------
# 安装后执行的脚本
%post
echo "---------------------post"
#-----------------------------------------------------
#在卸载包之前运行
%preun
echo "---------------------preun"
#-------------------------------------------------------
#在卸载包之后运行
echo "---------------------postun"
%postun
#------------------------------------------------------
#清理
%clean
echo "---------------------clean"
#rm -rf %{buildroot}
#rm -rf %{buildroot}/%{name}-%{version}
#-----------------------------------------------------
#rpm包中要安装的所有文件列表 文件中也可以包含通配符，如*
%files
#---
#设置默认权限，如果没有指定，则继承默认的权限
%defattr (-,root,root,0755)
%{user_path}
