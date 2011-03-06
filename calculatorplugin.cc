// プラグイン情報の記述。NP_GetValue関数をコールされることでプラグイン情報が取得される。
#include <npapi.h>

extern "C" {
    const char *NP_GetMIMEDescription(void) {
        return "application/x-calculator::Four Arithmetic Operations";
    }

    NPError NP_GetValue(NPP instance, NPPVariable variable, void *value) {
        switch(variable) {
        case NPPVpluginNameString:
            // プラグイン名を返却
            *static_cast<const char **>(value) = "x-calculator";
            break;
        case NPPVpluginDescriptionString:
            // プラグインの説明文字列を返却
            *static_cast<const char **>(value) = "Four Arithmetic Operations";
            break;
        default:
            return NPERR_INVALID_PARAM;
            break;
        }
        return NPERR_NO_ERROR;
    }
}
