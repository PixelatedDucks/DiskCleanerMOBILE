import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import android.widget.Button
import android.widget.LinearLayout
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val layout = LinearLayout(this)
        layout.orientation = LinearLayout.VERTICAL

        val pm = packageManager
        val apps = pm.getInstalledApplications(PackageManager.GET_META_DATA)

        apps.forEach { app ->
            // Here you could filter unused apps by some criteria
            val button = Button(this)
            button.text = "Uninstall ${pm.getApplicationLabel(app)}"
            button.setOnClickListener {
                val intent = Intent(Intent.ACTION_DELETE)
                intent.data = Uri.parse("package:${app.packageName}")
                startActivity(intent)
            }
            layout.addView(button)
        }

        setContentView(layout)
    }
}
