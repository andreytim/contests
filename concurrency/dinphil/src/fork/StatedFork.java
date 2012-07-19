/**
 * $Id$
 */
package fork;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class StatedFork extends Fork
{
    public static enum ForkState {
        IN_USE, FREE
    }
    
    public volatile ForkState state = ForkState.FREE;
}
