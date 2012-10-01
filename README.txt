Principes de conception, règle de codage...

* Règles de nommage à la Java (types/classes en CamelCaps, variables en camelCaps) :
*- class Foo
*- void Foo::funcName(void)
*- int countCalibration
* Favoriser la composition par rapport à l'héritage (utiliser un membre au lieu de dériver une classe)
* Utiliser systématiquement les liste d'initialisation du constructeur
* Utiliser les containeurs de la STL avec les pointeurs intelligents de Boost
*- définir un type "boost::shared_ptr<Cls> Ptr" public dans chaque classe concernée
*- définir un type "std::vector<Cls::Ptr> Vector" (resp List, Map...)
