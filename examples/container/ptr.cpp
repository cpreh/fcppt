//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[container_ptr
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4512)
#include <boost/ptr_container/ptr_map.hpp>
FCPPT_PP_POP_WARNING

namespace
{

struct noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	noncopyable()
	{
	}

	~noncopyable()
	{
	}
private:
	// some noncopyable data
};

}

int main()
{
	typedef boost::ptr_map<
		int,
		::noncopyable
	> int_noncopyable_map;

	int_noncopyable_map map;

	// insert a pair(42, unique_ptr<noncopyable>())
	fcppt::container::ptr::insert_unique_ptr_map(
		map,
		42,
		fcppt::make_unique_ptr<
			noncopyable
		>()
	);

	// print the address of the newly inserted element
	fcppt::io::cout
		<< &map[42]
		<< FCPPT_TEXT('\n');
}
//]
