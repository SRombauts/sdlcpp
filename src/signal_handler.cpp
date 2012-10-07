#include "signal_handler.h"

#ifdef unix

#include <iostream>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void signal_handler (const int aSigNum);

/**
 * @brief  Handler des signaux critiques
 *
 *  Produit les infos utiles à l'analyse du crash dans un fichier "crash_report.txt"
 * et sur la sortie console (utile en mise au point).
 *
 * @param[in]  aSigNum  Numéro du signal
 *
 * @author 2012/10/07 SRombauts
*/
void signal_handler (const int aSigNum)
{
    std::cout << "signal_handler: Signal " << aSigNum << ": " << strsignal(aSigNum) << std::endl;

    // S'il s'agit d'un des 5 signaux générant un Core par défaut
    if (   (aSigNum == SIGQUIT)
        || (aSigNum == SIGILL)
        || (aSigNum == SIGABRT)
        || (aSigNum == SIGFPE)
        || (aSigNum == SIGSEGV) )
    {
        // Réactive le traitement par défaut de ce signal et le relève
        signal(aSigNum, SIG_DFL);
        raise(aSigNum);
    }
    else
    {
        // Réactive le traitement par défaut du signal ABORT et le lève
        signal(SIGABRT, SIG_DFL);
        abort();
    }
}


void install_signal_handler(void)
{
    signal (SIGHUP,  signal_handler);   // Hangup (POSIX)
    signal (SIGINT,  signal_handler);   // CTRL-C / Interrupt (ANSI)
    signal (SIGQUIT, signal_handler);   // Quit (POSIX)
    signal (SIGILL , signal_handler);   // Illegal instruction (ANSI)
    signal (SIGABRT, signal_handler);   // Abort (ANSI) : exception non catchée, assert(), abort () ou BOOST_ASSERT()
    signal (SIGFPE,  signal_handler);   // Floating point error ou division par zéro
//  signal (SIGKILL, signal_handler);   // kill -9 : n'est pas capturable
    signal (SIGSEGV, signal_handler);   // Segmentation violation (ANSI) (Seg Fault)
    signal (SIGPIPE, signal_handler);   // Broken pipe (POSIX)
    signal (SIGTERM, signal_handler);   // kill (ou halt/shutdown)
    signal (SIGSTKFLT,signal_handler);  // Stack fault
//  signal (SIGSTOP, signal_handler);   // Stop, unblockable (POSIX)
    signal (SIGTSTP, signal_handler);   // CTRL-Z / Keyboard stop (POSIX)
    signal (SIGSYS,  signal_handler);   // Bad system call
}

#else

void install_signal_handler(void)
{
}

#endif
