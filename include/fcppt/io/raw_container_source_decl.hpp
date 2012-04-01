//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_DECL_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/io/raw_container_source_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iostreams/concepts.hpp>
#include <ios>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{
/**
\brief An alternative to boost::iostreams::array_source which has ownership

This is a replacement for boost::iostreams::array_source. The problem with
array_source is that it doesn't have ownership over the range.
raw_container_source has ownership.
*/
template<typename Container>
class raw_container_source
{
FCPPT_NONASSIGNABLE(
	raw_container_source);
public:
	typedef
	char
	char_type;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

	struct category
	:
		boost::iostreams::input_seekable,
		boost::iostreams::device_tag
	{
	};

FCPPT_PP_POP_WARNING

	typedef
	Container
	container;

	typedef
	fcppt::shared_ptr<container>
	container_ptr;

	typedef typename
	container::const_iterator
	const_iterator;

	template<typename Iterator>
	raw_container_source(
		Iterator,
		Iterator);

	raw_container_source(
		raw_container_source const &
	);

	~raw_container_source();

	std::streamsize
	read(
		char *,
		std::streamsize);

	std::streampos
	seek(
		boost::iostreams::stream_offset,
		std::ios_base::seekdir);
private:
	container_ptr const chars_;
	const_iterator pos_;
};
}
}

#endif
