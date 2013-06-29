/*
 * Requirements: libgtk-3-dev, valac
 *
 * Build: valac --pkg gtk+-3.0 jpdict.vala
 *
 * This file contains a very quick&dirty implementation of a Japanese to
 * English dictionary. We just wait for the user to select some text, then
 * we get it (from the clipboard) and find the meaning in the internet.
 */
using Gtk;

int main (string[] args) {
    Gtk.init (ref args);

    var window = new Window(0);
    window.title = "Japanese->English dictionary in GTK+";
    window.set_default_size(300, 50);
    window.destroy.connect(Gtk.main_quit);

    var translation = new Label ("Select something");
    var clip = Gtk.Clipboard.get(Gdk.Atom.intern("PRIMARY", false));

    clip.owner_change.connect(() => {
        string word = clip.wait_for_text();
        clip.clear();
        stdout.printf ("Definition of %s:\n", word);
        var web = File.new_for_uri ("http://tangorin.com/general/" + word);
        try{
            var stream = new DataInputStream (web.read (null));
            string line;
            // m:'<ol><li>today; this day</li>...}
            var regex = new Regex ("m:'<ol><li>(.*?)</li>");
            while ((line = stream.read_line (null,null)) != null) {
                if (regex.match (line)) {
                    var meaning = regex.split (line);
                    stdout.printf ("%s\n", meaning[1]);
                    translation.label = meaning[1];
                    break;
                }
            }
        } catch (Error e) {
            error ("%s", e.message);
        }
    });

    window.add (translation);
    window.show_all ();

    Gtk.main ();
    return 0;
}
