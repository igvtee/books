void print_ledger(int ledger)
{
#ifdef OPTION_LONG
	print_ledger_long(ledger);
#elif define OPTION_DETAILED
	print_ledger_detailed(ledger);
#else
	print_ledger_default(ledger);
#endif
}
