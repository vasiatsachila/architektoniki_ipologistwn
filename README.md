# Αρχιτεκτονική Υπολογιστών Lab1

## Απαντήσεις ερωτημάτων: 

### Ερώτημα  1 - Ερώτημα 2:

### Βασικές παράμετροι από το αρχείο _starter\_se.py_ , μαζί με στοιχεία από τα αρχεία: _stats.txt_ και _config.ini_.

**CPU type**: 

#### Starter_se.py: 	


\# Pre-defined CPU configurations. Each tuple must be ordered as : (cpu\_class, l1\_icache\_class, l1\_dcache\_class, walk\_cache\_class, l2\_Cache_class). Any of the cache class may be 'None' if the particular cache is not present.

    cpu_types = {
        "atomic" : ( AtomicSimpleCPU, None, None, None, None),
        "minor" : (MinorCPU,
                   devices.L1I, devices.L1D,
                   devices.WalkCache,
                   devices.L2),
        "hpi" : ( HPI.HPI,
                  HPI.HPI_ICache, HPI.HPI_DCache,
                  HPI.HPI_WalkCache,
                  HPI.HPI_L2)}
                  

#### Configs.ini: 
[system.cpu_cluster.cpus]
type=MinorCPU


----------------------------


**Frequency** :

Clock = 250 => frequency = 2GHz

#### Stats.txt: 
system.cpu\_cluster.clk_domain.clock               250                       \# Clock period in ticks

-----------------------------

**Caches**:

\# l1\_icache\_class, l1\_dcache\_class, walk\_cache\_class, l2\_Cache_class). Any of
 the cache class may be 'None' if the particular cache is not present.

    "hpi" : ( HPI.HPI,
              HPI.HPI_ICache, HPI.HPI_DCache,
              HPI.HPI_WalkCache,
              HPI.HPI_L2)
#### Stats.txt: 
l1\_icache\_class: system.cpu\_cluster.toL2Bus.pkt\_count\_system.cpu\_cluster.cpus.icache.mem\_side::system.cpu\_cluster.l2.cpu_side          668                       \# Packet count per connected master and slave (bytes) 

l1\_dcache\_class: system.cpu\_cluster.toL2Bus.pkt\_count\_system.cpu\_cluster.cpus.dcache.mem\_side::system.cpu\_cluster.l2.cpu_side          297                       \# Packet count per connected master and slave (bytes)

walk\_cache\_class: system.cpu\_cluster.cpus.itb\_walker_cache.pwrStateResidencyTicks::UNDEFINED     24087000                      
\# Cumulative time (in ticks) in various power states

------------------------------------

**Memory**: 
#### Starter_se.py:

    parser.add_argument("--mem-type", default="DDR3_1600_8x8",
                        choices=ObjectList.mem_list.get_names(),
                        help = "type of memory to use")
    parser.add_argument("--mem-channels", type=int, default=2,
                        help = "number of memory channels")
    parser.add_argument("--mem-ranks", type=int, default=None,
                        help = "number of memory ranks per channel")
    parser.add_argument("--mem-size", action="store", type=str,
                        default="2GB",
                        help="Specify the physical memory size")

#### Stats.txt: 
host\_mem\_usage                                2258996                       \# Number of bytes of host memory used

### Απαντήσεις στο ερώτημα 3:

Minor CPU model:  Είναι ένα in-order μοντέλο επεξεργαστή με συγκεκριμένο pipeline αλλά διαμορφώσιμα δεδομένα, δομές και τρόπο εκτέλεσης. Ακολουθεί αυστηρά την σε σειρά εκτέλεση εντολών και επιτρέπει την οπτικοποίηση της θέσης μιας  εντολής στην σειρά εντολών μέσω ορισμένων λειτουργειών. Ο σκοπός του είναι να προσφέρει ένα πλαίσιο, σε επίπεδο μικροαρχιτεκτονικής, που να συσχετίζει το μοντέλο με κάποιον συγκεκριμένο επεξεργαστή με παρόμοιες ιδιότητες. 


### Απαντήσεις στο ερώτημα 3a: 
Για το ερώτημα χρησιμοποιήθηκε το αρχείο κώδικα test2, ο κώδικας δημιουργεί έναν τυχαίο πίνακα 100 αριθμών τύπου integer, τους ταξινομεί σε αύξουσα σειρά και εκτυπώνει το αποτέλεσμα. Χρησιμοποιήθηκαν επίσης 3 διαφορετικοί τύποι CPU: AtomicSimple, TimingSimple, Minor.

#### CPU type= AtomicSimple


final_tick                                  183135000                       \# Number of ticks from beginning of simulation (restored from checkpoints

host_seconds                                     0.19                       \# Real time elapsed on the host

sim_freq                                 1000000000000                       \# Frequency of simulated ticks

sim_seconds                                  0.000183                       \# Number of seconds simulated

-----------------------------------------------------

#### CPU type= TimingSimpleCPU 

final_tick                                25001187000                       \# Number of ticks from beginning of simulation (restored from checkpoints and never reset)

host_seconds                                     0.91                       \# Real time elapsed on the host

sim_freq                                 1000000000000                       \# Frequency of simulated ticks

sim_seconds                                  0.025001                       \# Number of seconds simulated

----------------------------------------------------

#### CPU type=MinorCPU

final_tick                                  226698000                       \# Number of ticks from beginning of simulation (restored from checkpoints and never reset)

host_seconds                                     0.83                       \# Real time elapsed on the host

sim_freq                                 1000000000000                       \# Frequency of simulated ticks

sim_seconds                                  0.000227                       \# Number of seconds simulated


### Απαντήσεις στο ερώτημα 3b:

Παρατηρείται μια διαφορά στον χρόνο εκτέλεσης μεταξύ TimingSimpleCPU και της MinorCPU καθώς επίσης και μεγάλη διαφορά του πόσο συχνά χρησιμοποιείτε η cache. Βλέπουμε ότι στην MinorCPU  που χρησιμοποιεί πολύ συχνά την cache. Ίσως το γεγονός αυτό οδηγεί στο να είναι ελαφρώς πιο γρήγορη η MinorCPU. 


### Βιβλιογραφία: 
http://www.gem5.org/docs/html/minor.html
http://gem5.org/SimpleCPU





