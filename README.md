<h1 align="center">Image Viewer for the Numworks Calculator</h1>
<p align="center">
    <img alt="Version" src="https://img.shields.io/badge/Version-0.0.1-blue?style=for-the-badge&color=blue">
    <img alt="Stars" src="https://img.shields.io/github/stars/SaltyMold/Image-Viewer-For-Numworks?style=for-the-badge&color=magenta">
    <img alt="Forks" src="https://img.shields.io/github/forks/SaltyMold/Image-Viewer-For-Numworks?color=cyan&style=for-the-badge&color=purple">
    <img alt="License" src="https://img.shields.io/github/license/SaltyMold/Image-Viewer-For-Numworks?style=for-the-badge&color=blue">
    <br>
    <a href="https://github.com/SaltyMold"><img title="Developer" src="https://img.shields.io/badge/Developer-SaltyMold-red?style=flat-square"></a>
    <img alt="Maintained" src="https://img.shields.io/badge/Maintained-No-blue?style=flat-square">
    <img alt="Written In" src="https://img.shields.io/badge/Written%20In-C-yellow?style=flat-square">
</p>

_This app is an **Image viewer** that runs on the **[NumWorks Calculator](https://www.numworks.com)**, allowing users to watch the image that they have installed on it._

## ⚙️ Install the app

To install this app, you'll need to:
1. Go to this page I have Created : https://saltymold.github.io/Image-Viewer-For-Numworks/
2. Upload your Image and Connect your Calculator
3. And you'r Done, just Click Install and Enjoy


Supported Image Formats are :
-PNG    -JPEG    -AVIF    -BMP    -WEBP

## How to use the app

Just open the Application on your Calculator, to exit press ON/OFF HOME or BACK

## 🛠️ Build the app

### Requirements:

- **arm-none-eabi-gcc**
- **nodejs 18.20.7 (install n for 18.20.7 version)**
- **nwlink (with npm)**
- **make 4.3**
- **git (optional)**

To build this sample app, you will need to install the **[embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain)** and **[Node.js](https://nodejs.org/en/) 18**. The C SDK for Epsilon apps is shipped as an **npm module called [nwlink](https://www.npmjs.com/package/nwlink) v0.0.16**.

### Debian

```sh
sudo apt install -y build-essential git gcc-arm-none-eabi binutils-arm-none-eabi nodejs npm && npm install -g n && sudo n 18 && npm install -g nwlink@0.0.16
git clone https://github.com/SaltyMold/Image-Viewer-For-Numworks.git
cd Image-Viewer-For-Numworks
make clean && make build
```

### Windows

You can install MSYS2 with all dependencies preinstalled from my [C-App-Guide-for-Numworks](https://github.com/SaltyMold/C-App-Guide-for-Numworks) or install all manually with the instructions bellow.

Install msys2 from [the MSYS2 Github](https://github.com/msys2/msys2-installer/releases/download/2025-02-21/msys2-x86_64-20250221.exe) and open the msys2.exe file.
Download the .zip from [the Node Github](https://github.com/actions/node-versions/releases/download/18.20.7-13438827950/node-18.20.7-win32-x64.7z), and extract it.

```sh
#MSYS2

pacman -Syu

#Replace with the reel node path
echo 'export PATH="/c/Users/UserName/AppData/Local/Programs/node-18.20.7-win32-x64:$PATH"' >> ~/.bashrc
source ~/.bashrc

npm install -g nwlink@0.0.16
nwlink --version
```

```ps
#PowerShell

#You can chose a diferent path
$env:ChocolateyInstall = "$env:LOCALAPPDATA\Programs\choco"
[System.Environment]::SetEnvironmentVariable("ChocolateyInstall", $env:ChocolateyInstall, "User")

Set-ExecutionPolicy Bypass -Scope Process -Force
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

$env:Path += ";$env:ChocolateyInstall\bin"
[System.Environment]::SetEnvironmentVariable("Path", $env:Path, "User")
choco --version

choco install make --version=4.3 -y --force
make --version
```

```sh
#MSYS2

#Replace with the reel make path
echo 'export PATH="/c/Users/UserName/AppData/Local/Programs/choco/make/bin:$PATH"' >> ~/.bashrc 
source ~/.bashrc

pacman -S --noconfirm mingw-w64-x86_64-arm-none-eabi-gcc
arm-none-eabi-gcc --version

pacman -S --noconfirm git
git --version
git clone https://github.com/SaltyMold/Image-Viewer-For-Numworks.git

cd Image-Viewer-For-Numworks
make clean && make build
```

You should now have a **`output/app.nwa` file** that you can distribute! Anyone can now install it on their calculator from the **[NumWorks online uploader](https://my.numworks.com/apps)**.

## 🛠️ Build your own app

To build your own app, start by cloning the repository:

```sh
git clone https://github.com/SaltyMold/Image-Viewer-For-Numworks.git
```
Inside the project, you'll find **`eadk.h`**, which provides **essential functions** for interacting with the **[calculator](https://en.wikipedia.org/wiki/NumWorks)**. Modify **`main.c`** to implement your **own code**.
Additionally, make sure to include an **`icon.png`** with dimensions **55×56 pixels** to serve as your **app’s icon**. Once your modifications are done, link the app with **[nwlink](https://www.npmjs.com/package/nwlink)** and enjoy your app!

## 🌟 Special thanks 

I followed the guide from **[epsilon-sample-app-c](https://github.com/numworks/epsilon-sample-app-c)** to build this app.

I customized the NumWorks **[App Transfer WebSite](my.numworks.com/apps)** to make it easier and more user-friendly for sending Applications to the Calculator.
