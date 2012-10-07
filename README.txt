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
* Jamais de new/delete (boost::make_shared)

Boost guidelines :
Often the best way to deal with exceptions is to not handle them at all. If you can let them pass through your code and allow destructors to handle cleanup, your code will be cleaner.

Boost - utilisation de :
<boost/shared_ptr.hpp> : encapsule l'allocation/libération mémoire d'un objet par comptage de références (évite tous les "delete")
<boost/make_shared.hpp> : factory produisant un shared_ptr (évite tous les "new", et améliore l'allocation mémoire en faisant d'un bloc l'allocation de l'objet et du compteur de références)
<boost/enable_shared_from_this.hpp> : permet d'obtenir un shared_ptr de "this" à l'aide de shared_from_this() dès lors que "this" à été créé avec un shared_ptr
<boost/weak_ptr.hpp> : permet d'obtenir une référence faible utile pour ne pas retenir un objet qui n'est plus utilisé ailleurs (NECESSAIRE dans le cas d'une référence croisée)  
BOOST_ASSERT et BOOST_ASSERT_MSG

Boost - pas d'utilisation de :
A shared_ptr to a std::vector is an alternative to a "shared_array" that is a bit heavier duty but far more flexible.
If it isn't obvious whether "intrusive_ptr" better fits your needs than "shared_ptr", try a shared_ptr-based design first.
boost::exception et BOOST_THROW_EXCEPTION : utile uniquement si l'on fait un handler d'exceptions (ce qui n'est pas conseillé en debug)
std::set_terminate(terminate_handler); idem, pratique pour afficher plus d'infos sur une exception (fichier, ligne, backtrace...)
