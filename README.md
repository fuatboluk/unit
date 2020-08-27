# unit

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-help.png "Unit Screenshot")

## English

The unit is a unifying command line interface that runs all executable programs attached to the path on the operating system and user added scripts under a single command, based on user permissions.

By running all the shell files added to the /scripts directory with their arguments as if they were included in the same program, it allows you to make the program more functional and group many properties.

# Compiling and Running

* Run the `make` command in the source directory.
* When the compilation is completed, a binary file with the name of unit will be created in the directory you are in. Copy this file into the `/usr/bin` directory.
* Create the `/scripts` directory on the root directory and create all the shell functions you want to add to this directory.

# Explanation

The unit can execute all executable programs on the system, script files and add-ons added by the user through a single interface.

The purpose of this program is to safely run shell functions encoded in text files that are not allowed to run under normal conditions, and to help you automate all kinds of processes by constantly improving their capabilities with the add-on method.

It allows you to simulate all other programs in the system and run them over the unit interface. If you encode complex arguments and very long code as unit script once, instead of typing them every time. You can make all your transactions by typing paramters in speaking fluency.

-----------------------------------------------------------------------------

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-example1.png "Unit Example1 Screenshot")

## Turkish

unit, işletim sistemindeki yola bağlı tüm çalıştırılabilir programları çalıştıran ve kullanıcı izinlerine bağlı olarak kullanıcı tarafından eklenen komut dosyalarını tek bir komut altında çalıştıran birleştirici bir komut satırı arayüzüdür.

/scripts dizinine eklenen tüm kabuk dosyalarını, argümanları ile aynı programa dahil edilmiş gibi çalıştırarak, programı daha işlevsel hale getirmenize ve birçok özelliği gruplamanıza olanak tanır.

 # Derleme ve Çalıştırma

 * Kaynak dizin içerisinde `make` komutunu koşun.
 * Derleme tamamlanınca bulunduğunuz dizinde unit adı ile bir ikili dosya oluşacaktır. Bu dosyayı `/usr/bin` dizini içine kopyalayın.
 * Kök dizin üzerinde `/scripts` dizini oluşturun ve eklemek istediğiniz tüm kabuk fonksiyonlarını bu dizine oluşturun.

 # Açıklama

ünite sistem üzerindeki tüm çalıştırılabilir programları, betik dosyalarını ve kullanıcı tarafından eklenen eklentileride dahil tek arabirim üzerinden yürütebilir.

Bu programın amacı, normal şartlarda çalıştırma izni olmayan metin dosyalarına kodlanmış kabuk fonksiyonlarını güvenli şekilde çalıştırmak ve eklenti yöntemi ile kabiliyetlerini sürekli geliştirerek her türlü işlemi otomatize etmenize yardımcı olmaktır.

Sistemdeki diğer tüm programları simüle ederek unit arabirimi üzerinden çalıştırmanızada olanak verir. Karmaşık argümanlar ve çok uzun kodları her seferinde yazmak yerine, bir kez unit betiği olarak kodlarsanız. konuşma akıcılığında paramtre yazarak tüm işlemlerinizi yaptırabilirsiniz.