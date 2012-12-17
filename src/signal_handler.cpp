#include "signal_handler.h"

#ifdef unix

#include <iostream>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


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
    struct sigaction  sa;

    // Init de la structure sigaction
    memset (&sa, 0, sizeof (sa));
    sa.sa_handler = signal_handler;
    sigaction (SIGHUP,  &sa, NULL); // Hangup (POSIX)

    sigaction (SIGHUP,  &sa, NULL); // Hangup (POSIX)
    sigaction (SIGINT,  &sa, NULL); // CTRL-C / Interrupt (ANSI)
    sigaction (SIGQUIT, &sa, NULL); // Quit (POSIX)
    sigaction (SIGILL , &sa, NULL); // Illegal instruction (ANSI)
    sigaction (SIGABRT, &sa, NULL); // Abort (ANSI) : exception non catchée, assert(), abort () ou BOOST_ASSERT()
    sigaction (SIGFPE,  &sa, NULL); // Floating point error ou division par zéro
//  sigaction (SIGKILL, &sa, NULL); // kill -9 : n'est pas capturable
    sigaction (SIGSEGV, &sa, NULL); // Segmentation violation (ANSI) (Seg Fault)
    sigaction (SIGPIPE, &sa, NULL); // Broken pipe (POSIX)
    sigaction (SIGTERM, &sa, NULL); // kill (ou halt/shutdown)
    sigaction (SIGSTKFLT,&sa, NULL);// Stack fault
//  sigaction (SIGSTOP, &sa, NULL); // Stop, unblockable (POSIX)
    sigaction (SIGTSTP, &sa, NULL); // CTRL-Z / Keyboard stop (POSIX)
    sigaction (SIGSYS,  &sa, NULL); // Bad system call
}

#else

void install_signal_handler(void)
{
}

#endif
