Buidler模式意图：
  将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。

Builder模式中，Director类的作用：
 第一，它隔离了客户及生产过程。第二，它负责控制产品的生成过程。

Builder模式与AbstractFactory模式的区别:

建造者模式（Builder)与抽象工厂模式很相象，但是，Builder返回完整的一个产品，
而AbstractFactory返回一系列有关系的产品；在抽象工厂模式中，客户采用
AbstractFactory生成自己要用的对象，而在建造者模式中，客户指导Builder类
如何生成对象，或者如何合成一些类来构成建造类，侧重于一步步构造一个复杂
对象，然后将结果返回。