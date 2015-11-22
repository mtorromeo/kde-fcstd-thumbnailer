# FreeCAD Thumbnail Creator

KDE thumbnail-plugin that generates small images (thumbnails) for FcStd (FreeCAD) files, to be displayed, for example, on Konqueror and Dolphin file managers.

## Dependencies

The following libraries and development packages are needed:
KDE >=5.2.x
QT  >=5.2.x

## Building & installing

### Dependencies

_todo_

### Fetch the source

```bash
cd my_build_dir
git clone https://github.com/StefanHamminga/kde-fcstd-thumbnailer
```

### Build

```bash
cd kde-fcstd-thumbnailer
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=`kf5-config --prefix` ..
make
```

### Install

```bash
sudo make install
```

## Authors

The FreeCAD thumbnailer for KDE 5 is (re)written by [Stefan Hamminga](stefan@prjct.net) ([prjct.net](https://prjct.net)) and largely based on the KDE 4 thumbnailer by Yorik van Havre ([yorik.uncreated.net](http://yorik.uncreated.net)), which in turn is based on the KDE ODF thumbnailer by Ariel Constenla-Haile.

## License

This work is released under the terms of the LGPL 3.0 (GNU Lesser General Public License). The complete text is included in the `LICENSE` file. For online reference, consult:

http://www.fsf.org/licenses/lgpl.html

http://www.gnu.org/licenses/lgpl-3.0.txt

## Repositories

KDE 5: https://github.com/StefanHamminga/kde-fcstd-thumbnailer

KDE 4: https://github.com/yorikvanhavre/kde-fcstd-thumbnailer
