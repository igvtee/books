network_code()
{
	switch (line) {

		case THING1:
			doit1();
			break;

		case THING2:
			if (x == STUFF) {
				do_first_stuff();

				if (y == OTHER_STUFF)
					break;
				do_later_stuff();
			} /* coder meant to break to here... */
			initialize_modes_pointer();
			break;

		default:
			processing();
	} /* ...but actually broke to here! */

	use_modes_pointer(); /* leaving the modes_pointer uninitialized */
}
