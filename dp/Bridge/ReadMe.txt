Bridge模式用于将表示和实现解耦,两者可以独立的变化.在Abstraction类中维护
一个AbstractionImp类指针,需要采用不同的实现方式的时候只需要传入不同的
AbstractionImp派生类就可以了。