//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/c_deleter.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace
{

//! [scoped_ptr_factory_decl]
typedef std::unique_ptr<
	int
> int_unique_ptr;

// A factory returning an int_unique_ptr
int_unique_ptr
factory();
//! [scoped_ptr_factory_decl]

int_unique_ptr
factory()
{
	return
		fcppt::make_unique_ptr<
			int
		>(
			42
		);
}

//! [scoped_ptr_factory]
void
receive_int_ptr()
{
	typedef fcppt::scoped_ptr<
		int
	> int_scoped_ptr;

	// Take the int_unique_ptr and store it in a scoped_ptr
	int_scoped_ptr const result(
		factory()
	);

	fcppt::io::cout()
		<< *result
		<< FCPPT_TEXT('\n');
}
//! [scoped_ptr_factory]


//! [scoped_ptr_pimpl_decl]

// Only declare my_class
class my_class;

// holder owns a my_class object using a scoped_ptr. At this class definition,
// my_class doesn't have to be defined. However, you have to make sure that
// holder is not copyable, and that its constructor and destructor are not
// inline, because they would require my_class to be defined.
class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	holder();

	~holder();
private:
	fcppt::scoped_ptr<
		my_class
	> pimpl_;
};
//! [scoped_ptr_pimpl_decl]

//! [scoped_ptr_pimpl_def]
class my_class
{
	// Imaginge a huge class with a lot of stuff in it that should rather
	// not be included everywhere.
};

// Construct the scoped ptr pimpl_ using make_unique_ptr and take advantage of
// the fact that a scoped ptr can take ownership from a unique ptr.
holder::holder()
:
	pimpl_(
		fcppt::make_unique_ptr<
			my_class
		>()
	)
{
}

holder::~holder()
{
}
//! [scoped_ptr_pimpl_def]
}

int
main()
{
	receive_int_ptr();

//! [scoped_ptr_c_deleter]
	typedef fcppt::scoped_ptr<
		void,
		fcppt::c_deleter
	> void_c_ptr;

	void_c_ptr ptr(
		std::malloc(
			100
		)
	);
//! [scoped_ptr_c_deleter]

	holder foo;
}
//]
