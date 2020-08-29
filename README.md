# unit

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-help.png "Unit Screenshot")

## English

The unit is a unifying interface that allows you to make the program more functional and group many properties by running all the shell files added by the user to the / scripts directory as if they were included in the same program with their arguments.

# Compiling and Running

* Run the `make` command in the source directory.
* When the compilation is completed, a binary file with the name of unit will be created in the directory you are in. Copy this file into the `/usr/bin` directory.
* Move the scripts folder in the project to the root directory and create your own units in the same structure.

# Use of

Unit perceives the directories in the / scripts directory as a group due to its structure. You can access the group by giving these group names after the unit command. There is one _help file in each group directory. You can provide information about the group by typing group information, function usage within the group, etc. in this help file. You can also add separate usage outputs using shell syntax within each function file.

You can examine the sample function files in the scripts directory in the project and have more comprehensive information about how to use the unit.

Example usage syntax:

program_name group function parameters
----------------------------------------

unit firewall add_port 2834/tcp

or

unit wtime show

You can add as many group(unit) and function files to the unit as you want. If you write the shell operations that you use constantly as a unit function instead of always writing in more than one line, you can easily run them with simple parameters you specify in speech fluency and automate your work.

-----------------------------------------------------------------------------

![Alt text](https://gitlab.com/fuatboluk/unit/raw/master/unit-example1.png "Unit Example1 Screenshot")

## Turkish

Unit, kullanıcı tarafından eklenen tüm kabuk dosyalarını argümanları ile aynı programa dahil edilmiş gibi çalıştırarak programı daha işlevsel hale getirmenize ve birçok özelliği gruplamanıza olanak tanıyan birleştirici bir arabirimdir.

 # Derleme ve Çalıştırma

 * Kaynak dizin içerisinde `make` komutunu koşun.
 * Derleme tamamlanınca bulunduğunuz dizinde unit adı ile bir ikili dosya oluşacaktır. Bu dosya'yı `/usr/bin` dizini içine kopyalayın.
 * Proje içerisindeki scripts klasörünü kök dizine taşıyın ve aynı yapıda kendi ünitelerinizi oluşturun.

 # Kullanımı

Unit, yapısı itibariyle /scripts dizini içerisindeki dizinleri birer grup olarak algılar. unit komutundan sonra bu grup isimlerini vererek gruba erişebilirsiniz. Her grup dizini içerisinde bir adet _help dosyası bulunur. Bu yardım dosyası içerisine grup bilgilerini, grup içindeki fonksiyon kullanımlarını vs yazarak, grup hakkında bilgi sağlayabilirsiniz. Ayrıca her fonksiyon dosyası içerisinede kabuk söz dizimini kullanarak ayrı kullanım çıktıları ekleyebilirsiniz.

Projedeki scripts dizini içerisindeki örnek fonksiyon dosyalarını inceleyip, unit'i nasıl kullancağınız hakkında daha kapsamlı bilgiye sahip olabilirsiniz.

Örnek kullanım söz dizimi:

program_adı grup fonksiyon parametreler
----------------------------------------

unit firewall add_port 2834/tcp

veya

unit wtime show

unit'e istediğiniz kadar grup(ünite) ve fonksiyon dosyası ekleyebilirsiniz. Sürekli kullandığınız kabuk işlemlerini, birden fazla satırda herzaman yazmak yerine, birkez unit fonksiyonu olarak yazarsanız konuşma akıcılığında belirlediğiniz basit parametreler ile kolayca çalıştırıp işlerinizi otomatize edebilirsiniz.