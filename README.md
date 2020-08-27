# unit

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-help.png "Unit Screenshot")

## English

The unit is a unifying command line interface that runs all executable programs attached to the path on the operating system and user added scripts under a single command, based on user permissions.

By running all the shell files added to the /scripts directory with their arguments as if they were included in the same program, it allows you to make the program more functional and group many properties.

# Compiling and Running

* Run the `make` command in the source directory.
* When the compilation is completed, a binary file with the name of unit will be created in the directory you are in. Copy this file into the `/usr/bin` directory.
* Create the `/scripts` directory on the root directory and create all the shell functions you want to add to this directory.

-----------------------------------------------------------------------------

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-example1.png "Unit Example1 Screenshot")

## Turkish

unit, işletim sistemindeki yola bağlı tüm çalıştırılabilir programları çalıştıran ve kullanıcı izinlerine bağlı olarak kullanıcı tarafından eklenen komut dosyalarını tek bir komut altında çalıştıran birleştirici bir komut satırı arayüzüdür.

/scripts dizinine eklenen tüm kabuk dosyalarını, argümanları ile aynı programa dahil edilmiş gibi çalıştırarak, programı daha işlevsel hale getirmenize ve birçok özelliği gruplamanıza olanak tanır.

 # Derleme ve Çalıştırma

 * Kaynak dizin içerisinde `make` komutunu koşun.
 * Derleme tamamlanınca bulunduğunuz dizinde unit adı ile bir ikili dosya oluşacaktır. Bu dosyayı `/usr/bin` dizini içine kopyalayın.
 * Kök dizin üzerinde `/scripts` dizini oluşturun ve eklemek istediğiniz tüm kabuk fonksiyonlarını bu dizine oluşturun.